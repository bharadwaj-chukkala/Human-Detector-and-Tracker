#include <gtest/gtest.h>
#include <ReadData.hpp>

// TEST(dummy, should_pass) {
//   EXPECT_EQ(1, 1);
// }



TEST(readDataTest, read_success) {

  ReadData data1;
  std::string path = "../test_data/Lenna.png";
  cv::Mat frame;
  frame = data1.readFrame(path);
  EXPECT_FALSE(frame.empty());
}
