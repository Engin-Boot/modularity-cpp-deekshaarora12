#include <iostream>
#include<assert.h>
#include<string>
#include "testing_tele_color.h"

using namespace std;
using namespace TelCoColorCoder;

int computePairNumber(int majcol, int mincol) {
    return majcol * TelCoColorCoder::numberOfMinorColors + mincol + 1;
}

void getManualToString() {

    string manual_per_itr = "";
    string final_manual = "";
  
    for (int majorColor_itr = 0; majorColor_itr < TelCoColorCoder::numberOfMajorColors; majorColor_itr++) {
        manual_per_itr = "";
        for (int minorColor_itr = 0; minorColor_itr < TelCoColorCoder::numberOfMinorColors; minorColor_itr++) {
            string majorcolor_name = TelCoColorCoder::MajorColorNames[majorColor_itr];
            string minorcolor_name = TelCoColorCoder::MinorColorNames[minorColor_itr];
            int pairNumber = computePairNumber(majorColor_itr, minorColor_itr);

            string pair_number_to_string = std::to_string(pairNumber);

            manual_per_itr = manual_per_itr + pair_number_to_string + " " + majorcolor_name + " " + minorcolor_name + "\n";

       }
        final_manual = final_manual + manual_per_itr;
        
    } 
    cout<<final_manual<<endl;
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    getManualToString();
  
    return 0;
}
