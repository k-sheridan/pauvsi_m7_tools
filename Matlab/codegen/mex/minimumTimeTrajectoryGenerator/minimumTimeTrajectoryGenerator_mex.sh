MATLAB="/Applications/MATLAB_R2016a.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/kevinsheridan/.matlab/R2016a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for minimumTimeTrajectoryGenerator" > minimumTimeTrajectoryGenerator_mex.mki
echo "CC=$CC" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CFLAGS=$CFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CLIBS=$CLIBS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CXX=$CXX" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CXXLIBS=$CXXLIBS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "LD=$LD" >> minimumTimeTrajectoryGenerator_mex.mki
echo "LDFLAGS=$LDFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> minimumTimeTrajectoryGenerator_mex.mki
echo "Arch=$Arch" >> minimumTimeTrajectoryGenerator_mex.mki
echo OMPFLAGS= >> minimumTimeTrajectoryGenerator_mex.mki
echo OMPLINKFLAGS= >> minimumTimeTrajectoryGenerator_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> minimumTimeTrajectoryGenerator_mex.mki
echo "EMC_CONFIG=optim" >> minimumTimeTrajectoryGenerator_mex.mki
"/Applications/MATLAB_R2016a.app/bin/maci64/gmake" -B -f minimumTimeTrajectoryGenerator_mex.mk
