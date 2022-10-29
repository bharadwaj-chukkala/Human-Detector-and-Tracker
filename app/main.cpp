/**
 * MIT License

 * Copyright (c) [2022] [Bharadwaj Chukkala, Venkata Sairam Polina, and Shelvin Pauly]

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *  
 * @file HumanClassifier.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu)
 * @author Venkata Sairam Polina (sairamp@umd.edu)
 * @author Shelvin Pauly (spauly@umd.edu)
 * @brief Reads the data and process it
 * @version 0.1
 * @date 2022-10-15
 * 
 * 
 */

#include "PerceptionModule.hpp"
#include <string>

int main() {

    std::string filePath;
    int option;

    std::cout<<" ACME PERCEPTION MODULE \n"<<std::endl;
    std::cout<<"**** Enter filepath on on which detection should be carried****: "<<std::endl;
    std::getline(std::cin,filePath);

    std::cout<< "Enter the file Option: "<<std::endl
    <<"1.For Video Detection: press 0"<<std::endl<<"2.For Picture Detection: press 1"<<std::endl;
    std::cin>>option;

    PerceptionModule acmePerceptionModule(filePath,option);

    if (option==0){
        cv::VideoCapture cap(filePath);
    
        if(!cap.isOpened()){
            std::cout << "Error Loading video" << std::endl;
            return -1;
        }
    
        while(1){

            cv::Mat returnedFrame;
            // Capture frame-by-frame
            cap >> returnedFrame;

            int down_width = 650;
            int down_height = 700;
            cv::Mat returnedFrame1;
            //resize down
            cv::resize(returnedFrame, returnedFrame1, cv::Size(down_width, down_height), cv::INTER_LINEAR);

            // If the frame is empty, break immediately
            if (returnedFrame1.empty())
                break;

            // Display the resulting frame
            cv::imshow( "Frame", returnedFrame1 );
            acmePerceptionModule.acmeDetector.detectHumans(returnedFrame1);

            // Press  ESC on keyboard to exit
            char c=(char)cv::waitKey(25);
            if(c==27)
                break;
        }

        // When everything done, release the video capture object
        cap.release();

        // Closes all the frames
        cv::destroyAllWindows();

        return 0;

        }
    else{
        cv::Mat returnedFrame=acmePerceptionModule.frame.readFrame(filePath);

        // int down_width = 852;
        // int down_height = 480;
        // cv::Mat returnedFrame1;
        // //resize down
        // cv::resize(returnedFrame, returnedFrame1, cv::Size(down_width, down_height), cv::INTER_LINEAR);


        acmePerceptionModule.acmeDetector.detectHumans(returnedFrame);
        
        cv::waitKey(0);
        cv::destroyAllWindows();


    }

    
}