#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofTrueTypeFont::setGlobalDpi(72);
    ofSetBackgroundColor(0, 0, 0);
    verdana14.load("verdana.ttf", 14, true, true);
    verdana14.setLineHeight(18.0f);
    verdana14.setLetterSpacing(1.037);

    //parametric test. Rules also in page 43 of "The Algorithmic Beauty of Plants"
    string parametricRules;
    parametricRules += "A(x,y): y<=3 -> A(x*2,x+y);";
    parametricRules += "A(x,y): y>3 -> B(x)A(x/y,0);";
    parametricRules += "B(x) :x<1 -> C;";
    parametricRules += "B(x) : x>=1 -> B(x-1);";
    vector<string> expectedParametricResult {
        "B(2)A(4,4)",
        "B(1)B(4)A(1,0)",
        "B(0)B(3)A(2,1)",
        "CB(2)A(4,3)"
    };
    auto parametricTest = RuleTest("Parametric Grammar test",
                                   "B(2)A(4,4)",
                                   parametricRules,
                                   3,
                                   expectedParametricResult
                                   );
    parametricTest.executeTest();
    tests.push_back(parametricTest);

    // parametric test rule with constants
    vector<string> expectedParametricWithConstantsResult{
        "A(1)",
        "F(1)[+A(2)][-A(2)]"
    };
    map<string, float> constants;
    constants.insert(make_pair("R", 0.5));
    auto parametricWithConstants = RuleTest(
                                   "Parametric Grammar test with Constants",
                                   "A(1)",
                                   "A(s)->F(s)[+A(s/R)][-A(s/R)]",
                                   2,
                                   expectedParametricWithConstantsResult,
                                   constants
                                   );
    parametricWithConstants.executeTest();
    tests.push_back(parametricWithConstants);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int x = 20;
    int y = 20;
    for(auto test : tests){
        string text;
        if(test.isPassed()){
            ofSetColor(0,255,0);
            text = test.getTitle() += ": OK";
        }else{
            ofSetColor(255,0,0);
            text = test.getTitle() += ": ERROR, expected:\n";
            for(auto r :test.getExpectedResult()){
                text+= r + "\n";
            }
            text += "\ngot: \n";
            for(auto r :test.getResult()){
                text+= r + "\n";
            }
        }
        ofRectangle bounds = verdana14.getStringBoundingBox(text, 100, y);
        auto passed = test.isPassed() ? "OK" : "ERROR";
        verdana14.drawString(text , x, y );
        y += bounds.height+5;
    }
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
