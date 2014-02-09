//
//  ofxMSADataPathManager.cpp
//  Body Paint
//
//  Created by Memo Akten on 09/02/2014.
//
//

#include "MSADataPathManager.h"

#include "ofMain.h"


namespace msa {
    
    namespace DataPathManager {
        
        static string savedDataPath = "";
        
        void setDataPathToBundle() {
            savedDataPath = ofToDataPath("", false);
            string exeDir = ofFilePath::getCurrentExeDir();
            string contentsDir = ofFilePath::getEnclosingDirectory(exeDir);
            string resourcesDir = contentsDir + "Resources/";
            ofSetDataPathRoot(resourcesDir);
            //#ifdef MSA_TARGET_OSX
            //		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
            //		string newDataPath = string([[[NSBundle mainBundle] resourcePath] UTF8String]) + "/";
            //		printf("newDataPath : %s\n", newDataPath.c_str());
            //		ofSetDataPathRoot( newDataPath );
            //
            //		printf("testing : %s\n", ofToDataPath("myfile.bmp").c_str());
            //
            //		[pool release];
            //#endif
            //		ofDisableDataPath();
            
        }
        
        void restoreDataPath() {
            //		ofEnableDataPath();
            if(!savedDataPath.empty()) ofSetDataPathRoot(savedDataPath);
        }
        

    }
}