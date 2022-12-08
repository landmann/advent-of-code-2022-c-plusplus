#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


// Define the URL as a global variable
const std::string filepath = "input.txt";

// Point of this is to iterate through the file and sum the contents of the foods.
// When the line is over, compare to pre existing sum. If greater than sum, replace sum. Else, continue.

int32_t get_max_cals(
    std::vector<int32_t>& file_content)  // Solution for the first part
{
    int32_t max_calories = 0;
    int32_t current_calories = 0;

    for (int32_t cal : file_content)
    {
        if (cal == -1)
        {
            max_calories = std::max(max_calories, current_calories);
            current_calories = 0;
        } else
            current_calories += cal;
    }
    return max_calories;
}

// get the top 3 sum
int32_t get_top_3_sum (
    std::vector<int32_t>& file_content)
{
  // initialize list of sums
  std::vector<int32_t> sums;

  // initialize sums with three 0s
  for (int i = 0; i < 3; i++)
    sums.push_back(0);

  int32_t current_cals = 0;
  for (int32_t cal: file_content)
  {
    if (cal == -1)
    {
      // if current_cals is greater than 
      // sort sums in ascending order and assign to sums
      std::sort(sums.begin(), sums.end());
      for (int32_t& sum: sums)
      {
        if (current_cals > sum)
        {
          sum = current_cals;
          break;
        }
      }
      current_cals = 0;
    } else
      current_cals += cal;
  }
  // return sum of sums
  return std::accumulate(sums.begin(), sums.end(), 0);
}

int main()
{
  auto start_time = std::chrono::high_resolution_clock::now();

  std::ifstream input_file(filepath);

  if (!input_file.is_open()) return -1;

  std::string line;
  std::vector<int32_t> file_content;

  while (getline(input_file, line))
  {
    int32_t calories = -1;

    if (line.length() != 0) calories = std::stoi(line);

    file_content.push_back(calories);
  }

  /*                              Calculate                                  */
  int32_t res1 = get_max_cals(file_content);
  auto res2 = get_top_3_sum(file_content);

  /*                              Output                                     */

  std::cout << "Result 1:\t" << res1 << std::endl;
  std::cout << "Result 2:\t" << res2 << std::endl;
  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> mis_double = end_time - start_time;
  
  std::cout << "\nTotal duration:\t" << mis_double.count() << "μs" << std::endl;

  return EXIT_SUCCESS;
}