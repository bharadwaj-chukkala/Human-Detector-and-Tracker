#include <gtest/gtest.h>
#include <"../include/ReadData.hpp">

// TEST(dummy, should_pass) {
//   EXPECT_EQ(1, 1);
// }

DataReader data;
std::string path = "../test_data/Lenna.png";

TEST(DataReader, read_success) {

  cv::Mat frame;
  frame = data.ReadFrame(path)
  EXPECT_FALSE(frame.empty());
}
