//
//  GameScreen.h
//  Rac0r
//
//  Created by Jannes Meyer on 15.06.13.
//  Copyright (c) 2013 Jan Schulte. All rights reserved.
//

#ifndef __Rac0r__GameScreen__
#define __Rac0r__GameScreen__

#include <iostream>

#include "Screen.h"
#include "../track/TrackDrawable.h"
#include "../track/TrackLoader.h"
#include "../car/Car.h"

class GameScreen : public Screen, public Rac0r::CarEventListener {
private:
    std::string trackDir;
    // store tracks & track lines
    std::vector<Rac0r::Track> tracks;
    std::vector<Rac0r::TrackDrawable> trackDrawables;
    std::vector<Rac0r::Car> cars;
public:
    GameScreen(sf::VideoMode& videoMode);
    virtual void layout(sf::Time elapsed);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    
    virtual void onCarDriftedOffTrack(Rac0r::Car & _car) {
        std::cout << "Car drifted off track." << std::endl;
        //_car.resetToLastValidPosition();
    }
    
    virtual void onCarMovedThroughStart(Rac0r::Car & _car) {
        std::cout << "Car moved through start." << std::endl;
    }
    
    virtual void onCarStartedFromStart(Rac0r::Car & _car) {
        std::cout << "Car started from start." << std::endl;
    }
    
    virtual ~GameScreen() = default;
};

#endif /* defined(__Rac0r__GameScreen__) */
