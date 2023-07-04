#include <iostream>
#include <string>
#include <fstream>

int main() {
   std::ifstream statFile("/proc/stat"); // Arquivo que contém informações sobre a CPU
    std::ifstream statmFile("/proc/self/statm"); // Arquivo que contém informações sobre o uso da memória

  std::string line;

  std::getline(statFile, line); // Lê a primeira linha do arquivo
  statFile.close(); // Fecha o arquivo

  long unsigned int user, nice, system, idle;
  sscanf(line.c_str(), "cpu %lu %lu %lu %lu", &user, &nice, &system, &idle); // Lê os valores da linha

  // Calculando a carga da cpu

  long unsigned int total = user + nice + system + idle;
  float cpuLoad = (float)(total - idle) / total;

  std::cout << "CPU Usage: " << cpuLoad * 100 << "%" << std::endl;

  std::getline(statmFile, line); // Lê a primeira linha do arquivo
  statmFile.close(); // Fecha o arquivo

  long unsigned int memSize, resident, share, text, lib, data, dt;

  sscanf(line.c_str(), "%lu %lu %lu %lu %lu %lu %lu", &memSize, &resident, &share, &text, &lib, &data, &dt);


  std::cout << "Memory Usage: " << resident * 4 << " KB" << std::endl;

  return 0;
}