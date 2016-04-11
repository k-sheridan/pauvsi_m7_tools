

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.swing.JFileChooser;

import org.encog.Encog;
import org.encog.app.quant.indicators.predictive.BestClose;
import org.encog.engine.network.activation.ActivationStep;
import org.encog.ml.MLMethod;
import org.encog.ml.ea.opp.selection.SelectionOperator;
import org.encog.ml.ea.population.Population;
import org.encog.ml.ea.train.EvolutionaryAlgorithm;
import org.encog.ml.genetic.MLMethodGeneticAlgorithm;
import org.encog.ml.train.MLTrain;
import org.encog.neural.hyperneat.substrate.Substrate;
import org.encog.neural.hyperneat.substrate.SubstrateFactory;
import org.encog.neural.neat.NEATCODEC;
import org.encog.neural.neat.NEATNetwork;
import org.encog.neural.neat.NEATPopulation;
import org.encog.neural.neat.NEATUtil;
import org.encog.neural.neat.PersistNEATPopulation;
import org.encog.neural.neat.training.species.OriginalNEATSpeciation;
import org.encog.neural.networks.training.anneal.NeuralSimulatedAnnealing;
import org.encog.neural.networks.training.propagation.PersistTrainingContinuation;
import org.encog.persist.EncogDirectoryPersistence;

import processing.core.*;

public class Mission_7_Simulation extends PApplet {
	
	public static final int DRAW_TIMER_THRESHOLD = 100;
	
	public static final int MAX_GENERATION = 10000; // the maximum number of generations
	public static final int INPUTS = 10;
	public static final int OUTPUTS = 2;
	public static final int POPULATION_SIZE = 1000;
	public static final int TEST_TRIALS = 100;
	
	public long lastDraw = 0;

	/**
	 * I have no idea what this is lol, but eclipse wants it.
	 */
	private static final long serialVersionUID = -4005463489202428871L;
	
	//printer
	PrintWriter GameResults;
	PrintWriter BestGenomeResults;
	PrintWriter NNVis;
	PrintWriter NNSaver;
	long drawCount = 0;
	String folderPath = "data/";
	String currentRealTime = "";
	
	//NEAT
	NEATPopulation pop;
	EvolutionaryAlgorithm train;
	//current best neural network
	Game testGame;
	Game viewGame;
	NEATNetwork network;
	boolean testingNetwork = false; // always false at the start
	boolean viewPopulation = false;
	boolean continuingEvolution = false;
	int viewPopGameCount = 0;
	String viewPopulationPath = "";
	int testNetMin = 0;
	int testNetMax = 0;
	double testNetMean = 0;
	double fitness = 0;
	
	public void setup() 
	{
		size(800,800);
		background(20);
		if(viewPopulation)
		{
			final JFileChooser fc = new JFileChooser();
			fc.setCurrentDirectory(new File(this.sketchPath));
	        int returnVal = fc.showDialog(getParent(), "Population File");
	        
	        if(returnVal == JFileChooser.APPROVE_OPTION)
	        {
	        	File file = fc.getSelectedFile();
	        	viewPopulationPath = file.getAbsolutePath();
	        	//sets the train to the good population
	        	train = readPop(viewPopulationPath);
	        	currentRealTime = month() + "-" + day() + "_" + hour() + "-" + minute();
	        	GameResults = createWriter("data/Analysis/" + "analysis-" + currentRealTime + "/results.txt");
	        }
	        else
	        {
	        	exit();
	        }
		}
		else if(continuingEvolution)
		{
			final JFileChooser fc = new JFileChooser();
			fc.setCurrentDirectory(new File(this.sketchPath));
	        int returnVal = fc.showDialog(getParent(), "Population File for Evolving");
	        
	        if(returnVal == JFileChooser.APPROVE_OPTION)
	        {
	        	File file = fc.getSelectedFile();
	        	viewPopulationPath = file.getAbsolutePath();
	        	
	        	//setup the trainer with a evolved pop
	        	setupNEATtoContinue(viewPopulationPath);
	        }
	        else
	        {
	        	exit();
	        }
		}
		else
		{
			setupNEAT();
		}
	}

	public void draw() 
	{
		if(viewPopulation)
		{
			if(testingNetwork)
			{
				if(!testGame.isGameOver())
				{
					for(int i = 0; i < 1000; i++)
					{
						testGame.run();
					}
					visualizeGameDrawTimer(millis());
				}
				else
				{
					//run the statistic function and record data to a file
					printVisualizationResultsToFile(testGame);
					//null the testgame to conserve memory
					testGame = null;
					testingNetwork = false;
				}
			}
			else
			{
				testGame = new Game(this, (NEATNetwork)train.getCODEC().decode(train.getBestGenome()));
				viewPopGameCount++;
				testingNetwork = true;
			}
		}
		else
		{

			if(testingNetwork)
			{
				if(!testGame.isGameOver())
				{
					for(int i = 0; i < 20; i++)
					{
						testGame.run();
					}
					testGameDrawTimer(millis());
				}
				else
				{
					//null the testgame to conserve memory
					testGame = null;
					testingNetwork = false;
				}
			}
			else
			{
				evolve();
				//set up testGame and set testingNetwork to true
				testGame = new Game(this, network);
				testingNetwork = true;
			}

			if(train.getIteration() >= Mission_7_Simulation.MAX_GENERATION)
			{
				GameResults.flush();
				GameResults.close();
				BestGenomeResults.flush();
				BestGenomeResults.close();
				exit();
			}
		}
	}
	
	void printVisualizationResultsToFile(Game testGame)
	{
		GameResults.println(viewPopGameCount + "," + testGame.getFitness() + "," + testGame.getGameTime()
			+ "," + testGame.getOOBGreen() + "," + testGame.getOOBNotGreen() + "," + testGame.getNotOOB());
		
		GameResults.flush();
	}
	
	void evolve()
	{
		//run through an iteration
		train.iteration();
		//print debug info
		network = (NEATNetwork)train.getCODEC().decode(train.getBestGenome());
		
		//save the current best neural net
		//first actually save the net object for future use
		try {
			savePop(folderPath + "Saved_Neural_Networks/generation_" + train.getIteration() + "_population.pnp", ((NEATPopulation)train.getPopulation()));
		} catch (IOException e) {
			e.printStackTrace();
		}
		//save the individual neurons
		saveNNInfo(network);
		
		fitness = testNetwork(network);
		
		//print the best genome results to file
		BestGenomeResults.printf("%f,%d,%d,%f\n", fitness, testNetMin, testNetMax, testNetMean);
		
		System.out.printf("Best Neural Network Curent Performance- Fitness: %f \nMin OOBGreen: %d Max OOBGreen: %d Mean OOBGreen: %f\n", fitness, testNetMin, testNetMax, testNetMean);
		System.out.printf("Error: %f Max Generation: %d Best Neural Net Links: %d\n", train.getError(), train.getIteration(), network.getLinks().length);
		//flushes the Game results file
		GameResults.flush();
		BestGenomeResults.flush();
	}
	
	public void testGameDrawTimer(long millis)
	{
		background(73, 73, 73);
		testGame.draw();
		if(millis - lastDraw >= Mission_7_Simulation.DRAW_TIMER_THRESHOLD)
		{
			drawCount++;
			//add text to the screen of the game
			
			lastDraw = millis;
			//save the frame as an image 
			//saveFrame(new String(folderPath + "images/frame-" + String.format("%09d", drawCount) + ".tga"));
		}
	}
	
	public void visualizeGameDrawTimer(long millis)
	{
		background(73, 73, 73);
		testGame.draw();
		if(millis - lastDraw >= Mission_7_Simulation.DRAW_TIMER_THRESHOLD)
		{
			drawCount++;
			//add text to the screen of the game
			textSize(20);
			fill(255);
			text("Trial: ", 30, 30);
			text(viewPopGameCount, 150, 30);
			lastDraw = millis;
			//save the frame as an image 
			//saveFrame(new String("data/Analysis/" + "analysis-" + currentRealTime + "/Images/frame-" + String.format("%09d", drawCount) + ".tga"));
		}
	}
	
	public double testNetwork(MLMethod network)
	{	
		//OOBGreen = 0;
		ArrayList<Integer> OOBGreens = new ArrayList<Integer>(Mission_7_Simulation.TEST_TRIALS);
		double fitness = 0;
		boolean NNTouchedOOB = false;
		//play the game one last time to see if the fitness is repeatable
		for(int i = 0; i < Mission_7_Simulation.TEST_TRIALS; i++)
		{
			Game game = new Game(this, network);
			while(!game.isGameOver())
			{
				game.run();
			}
			
			
			fitness += game.getFitness();
			
			//add the oob green count to the array list
			OOBGreens.add(game.getOOBGreen());
		}
		
		//set the max oob greens
		testNetMax = 0;
		for(int i = 0; i < OOBGreens.size(); i++)
		{
			if(OOBGreens.get(i).intValue() > testNetMax)
			{
				testNetMax = OOBGreens.get(i).intValue();
			}
		}
		
		//set the min oob greens
		testNetMin = 10;
		for(int i = 0; i < OOBGreens.size(); i++)
		{
			if(OOBGreens.get(i).intValue() < testNetMin)
			{
				testNetMin = OOBGreens.get(i).intValue();
			}
		}
		
		//set the average oob greens
		testNetMean = 0;
		for(int i = 0; i < OOBGreens.size(); i++)
		{
			testNetMean += OOBGreens.get(i).doubleValue();
		}
		testNetMean /= Mission_7_Simulation.TEST_TRIALS;
		
		
		fitness = fitness / Mission_7_Simulation.TEST_TRIALS;
		
		return fitness;
	}
	
	public void savePop(String path, NEATPopulation pop) throws IOException
	{
		PersistNEATPopulation pnp = new PersistNEATPopulation();
		OutputStream os = createOutput(path);
		
		pnp.save(os, pop);
		os.flush();
		os.close();
	}
	
	public EvolutionaryAlgorithm readPop(String path)
	{
		InputStream is = createInput(path);
		
		EvolutionaryAlgorithm training2 = NEATUtil.constructNEATTrainer( 
				   (NEATPopulation)new PersistNEATPopulation().read(is), 
				   new Mission7Score(this, GameResults, NNVis));
		
		return training2;
	}
	
	
	/**
	 * saves the neurons of the network for visualization
	 * @param phenotype
	 */
	private void saveNNInfo(MLMethod phenotype)
	{
		//create a new writer
		NNVis = createWriter(folderPath + "NNVisualization/nn_" + train.getIteration() + ".txt");
		
		for(int i = 0; i < ((NEATNetwork)phenotype).getLinks().length; i++)
		{
			NNVis.printf("%d,%d,%f\n", ((NEATNetwork)phenotype).getLinks()[i].getFromNeuron(), ((NEATNetwork)phenotype).getLinks()[i].getToNeuron(),
					((NEATNetwork)phenotype).getLinks()[i].getWeight());
		}
		//NNVis.println("----------");
		NNVis.flush();
		NNVis.close();
	}
	
	public void setupNEAT()
	{
		//set up path
		folderPath += "Evolution_";
		folderPath += day();
		folderPath += "-";
		folderPath += hour();
		folderPath += "-";
		folderPath += minute();
		folderPath += "/";
		//create the loggers
		String path = "GameResults.txt";
		GameResults = createWriter(new String(folderPath + path));
		BestGenomeResults = createWriter(new String(folderPath + "BestGenomeResults.txt"));
		//NNVis = createWriter(new String(folderPath + "NNVisualization/startVis.txt"));
		
		Mission7Score score = new Mission7Score(this, GameResults, NNVis);
		//add 1 to the inputs for the bias! Important you idiot!!!!!!! Not you btw I'm talking to my self I'm sure your an intelligent person
		pop = new NEATPopulation(Mission_7_Simulation.INPUTS + 1, Mission_7_Simulation.OUTPUTS, Mission_7_Simulation.POPULATION_SIZE);
		//pop.setInitialConnectionDensity(0.7);
		//pop.setSurvivalRate(0.4);
		pop.reset();
		//create the NEAT Trainer
		train = NEATUtil.constructNEATTrainer(pop, score);
		
		OriginalNEATSpeciation speciation = new OriginalNEATSpeciation();
		speciation.setCompatibilityThreshold(1);
		train.setSpeciation(speciation = new OriginalNEATSpeciation());
	}
	
	public void setupNEATtoContinue(String popPath)
	{
		//set up path
		folderPath += "Evolution_";
		folderPath += day();
		folderPath += "-";
		folderPath += hour();
		folderPath += "-";
		folderPath += minute();
		folderPath += "/";
		//create the loggers
		String path = "GameResults_Continuation.txt";
		GameResults = createWriter(new String(folderPath + path));
		BestGenomeResults = createWriter(new String(folderPath + "BestGenomeResults_Continuation.txt"));
		//NNVis = createWriter(new String(folderPath + "NNVisualization/startVis.txt"));

		//Mission7Score score = new Mission7Score(this, GameResults, NNVis);
		//add 1 to the inputs for the bias! Important you idiot!!!!!!! Not you btw I'm talking to my self I'm sure your an intelligent person
		//pop = new NEATPopulation(Mission_7_Simulation.INPUTS + 1, Mission_7_Simulation.OUTPUTS, Mission_7_Simulation.POPULATION_SIZE);
		//pop.setInitialConnectionDensity(0.7);
		//pop.setSurvivalRate(0.4);
		//pop.reset();
		//create the NEAT Trainer from old population
		train = readPop(popPath);
		pop = ((NEATPopulation)train.getPopulation());

		OriginalNEATSpeciation speciation = new OriginalNEATSpeciation();
		speciation.setCompatibilityThreshold(1);
		train.setSpeciation(speciation = new OriginalNEATSpeciation());
	}
}
