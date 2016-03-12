#pragma once
#include "ofMain.h"

//external addond
// #include "ofxUnitTest"
#include "ofxLSGRuleStandard.h"
#include "ofxLSGRuleParametric.h"
#include "ofxLSGRuleStochastic.h"
#include "ofxLSGSanitizer.h"
#include "ofxLSGrammarDetector.h"
#include "ofxLSGrammarStochastic.h"
#include "ofxLSGrammarStandard.h"
#include "ofxLSGrammarParametric.h"

class ofxLSystemGrammar {
  public:
    static const string buildSentence(string _rules, const int _n_steps, string _axiom);
  private:
    static vector<string> putStringInContainer(string _str);
};