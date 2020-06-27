#include "src/graph/graph.h"
#include "src/tsp/sequentialTSP.h"

#define INITTIME   auto start = std::chrono::high_resolution_clock::now();\
  auto elapsed = std::chrono::high_resolution_clock::now() - start;\
  auto usec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();\

#define BEGINTIME start = std::chrono::high_resolution_clock::now();
#define ENDTIME(s,nw)   elapsed = std::chrono::high_resolution_clock::now() - start; \
  usec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();\
  cout << s << "\t" << usec << " usecs with " << nw << " threads " << endl;


int main(int argc, char *argv[]) {
  if (argc < 7) {
    std::cout << "Usage is " << argv[0]
              << " nodesNumber chromosomesNumber generationNumber mutationRate crossoverRate workersNumber seed filePath" << std::endl;
    return (-1);
  }

  int nodesNumber = std::atoi(argv[1]);
  int chromosomesNumber = std::atoi(argv[2]);
  int generationNumber = std::atoi(argv[3]);
  double mutationRate = std::atof(argv[4]); ;
  double crossoverRate = std::atof(argv[5]);;
  int workerNumber = std::atoi(argv[6]);
  int seed = 0;
  std::string filePath;

  if (argv[7]){
    std::atoi(argv[7]);
  }
  if (argv[8]) {
    filePath = argv[3];
  }

  Graph<> graph(nodesNumber);
  TSPSequential<> tsp(graph);
  tsp.Run(chromosomesNumber, generationNumber, mutationRate, crossoverRate, workerNumber, seed);
  return 0;
}