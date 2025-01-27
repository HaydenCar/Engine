//
//  engine.hpp
//  Engine
//
//  Created by Hayden Carr on 27/01/2025.
//

#ifndef engine_hpp
#define engine_hpp

class Engine{
public:
    void run();
    
private:
    void init();
    void mainLoop();
    void cleanup();
};

#endif /* engine_hpp */
