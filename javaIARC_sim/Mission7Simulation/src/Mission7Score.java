import java.io.PrintWriter;
import java.util.ArrayList;

import org.encog.ml.CalculateScore;
import org.encog.ml.MLMethod;
import org.encog.neural.neat.NEATNetwork;
import org.encog.neural.networks.training.anneal.NeuralSimulatedAnnealing;

import processing.core.PApplet;

public class Mission7Score implements CalculateScore{
	
	PApplet parent;
	PrintWriter results;
	PrintWriter nnDebug;
	public static final int TRIALS = 50;
	
	public Mission7Score(PApplet _parent, PrintWriter results, PrintWriter nnDebug) {
		//for drawing
		parent = _parent;
		this.results = results;
		this.nnDebug = nnDebug;
	}

	@Override
	public double calculateScore(MLMethod phenotype) {
		
		double fitness = 0;
		double averageRoombaOverGreen = 0;
		boolean NNTouchedOOB = false;
		
		//save all fitnesses
		ArrayList<Double> fitnesses = new ArrayList<Double>(Mission7Score.TRIALS);
		
		for(int i = 0; i < Mission7Score.TRIALS; i++)
		{
			//create the game and pass it the phenotype
			Game game = new Game(parent, phenotype);
			//run the game and do some magic in a couple hundred milliseconds
			while(!game.isGameOver())
			{
				game.run();
			}
			
			fitnesses.add(game.getFitness());
	
			averageRoombaOverGreen += game.getOOBGreen();
			
			//if a oob roomba was chosen
			if(game.getQuad().hasNNTouchedOOB())
			{
				NNTouchedOOB = true;
				fitness += 0;
			}
			else
			{
				fitness += game.getFitness();
			}
		}
		
		fitness = fitness / (double)Mission7Score.TRIALS;
		averageRoombaOverGreen = averageRoombaOverGreen / Mission7Score.TRIALS;
		
		//calculate stdDeviation
		double stdev = 0;
		for(int i = 0; i < Mission7Score.TRIALS; i++)
		{
			stdev += Math.abs(fitnesses.get(i).doubleValue() - fitness);
		}
		stdev = stdev / Mission7Score.TRIALS;
		
		//bias the oob greens and against stdev
		//fitness += (averageRoombaOverGreen * 1000f) - (stdev);
		
		//prints game results data to the file
		results.printf("%f,%f,%f,%d\n", fitness, averageRoombaOverGreen, stdev, ((NEATNetwork)phenotype).getLinks().length);
		
		//save neural net with fitness
		//this.saveNNInfo(fitness, phenotype);
		
		return fitness;
	}
	
	
	@Override
	public boolean requireSingleThreaded() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean shouldMinimize() {
		// TODO Auto-generated method stub
		return false;
	}

}
