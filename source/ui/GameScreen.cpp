//
//  GameScreen.cpp
//  Rac0r
//
//  Created by Jannes Meyer on 15.06.13.
//  Copyright (c) 2013 Jan Schulte. All rights reserved.
//

#include "GameScreen.h"

#include "ResourcePath.hpp"

GameScreen::GameScreen(const Rect& frame) : Screen(frame) {
    createTracks(5, "test5.track");
}

void GameScreen::createTracks(size_t _playerCount, const std::string & _trackFile) {

    // Load & Setup Main Track
    Rac0r::TrackLoader trackLoader;
    Rac0r::Track mainTrack = trackLoader.loadFromFile(resourcePath() + trackDir + _trackFile);
    
    float scaleOffset = 0.2;
    
    if (_playerCount % 2 == 0) {
        mainTrack.setCenter(sf::Vector2f(frame.width / 2, frame.height / 2));
        mainTrack.scaleToFitBounds(sf::Vector2f(frame.width, frame.height), false, -0.2);  // first initial scale
        mainTrack.scaleToFitBounds(sf::Vector2f(frame.width, frame.height), true, 8.0f);  // scale with directions
        tracks.push_back(mainTrack);
    
        float offset = 0.0f;
        for (size_t i = 0; i < _playerCount-1; i++) {
            Rac0r::Track subTrack = mainTrack;
            offset += (scaleOffset * 20.0f * static_cast<float>(i+1)) * (i % 2 == 0 ? -1.0f : 1.0f);
            
            subTrack.scaleToFitBounds(sf::Vector2f(frame.width, frame.height), true, offset);
            tracks.push_back(subTrack);
        }
        
    } else {
        mainTrack.setCenter(sf::Vector2f(frame.width / 2, frame.height / 2));
        mainTrack.scaleToFitBounds(sf::Vector2f(frame.width, frame.height), false, -0.2);
        tracks.push_back(mainTrack);
    
        float offset = 0.0f;
        for (size_t i = 0; i < _playerCount-1; i++) {
            Rac0r::Track subTrack = mainTrack;
            offset += (scaleOffset * 20.0f * static_cast<float>(i+1)) * (i % 2 == 0 ? 1.0f : -1.0f);
            
            subTrack.scaleToFitBounds(sf::Vector2f(frame.width, frame.height), true, offset);
            tracks.push_back(subTrack);
        } 
    }
    
    // create track line renderer
    unsigned int color = 0;
    sf::Color colors[5] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::White };
    for (auto & track : tracks) {
        Rac0r::TrackDrawable trackDrawable(track);
        trackDrawable.setThickness(2.0f);
        trackDrawable.setColor(colors[color]);
        trackDrawables.push_back(trackDrawable);
        
        // create cars for the track
        Rac0r::Car car(track, this);
        car.setColor(colors[color++]);
        cars.push_back(car);
    }
}

void GameScreen::layout(sf::Time elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        cars[0].accelerate();
        cars[1].accelerate();
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        cars[0].resetToLastValidPosition();
        cars[1].resetToLastValidPosition();
    }
    
    for (auto & car : cars) {
        car.update(elapsed);
    }
}

void GameScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // Render Tracks
    for (auto & trackDrawable : trackDrawables) {
        trackDrawable.draw(target, states);
    }
    
    // Render cars
    for (auto & car : cars) {
        car.draw(target, states);
    }
}


void GameScreen::onCarDriftedOffTrack(Rac0r::Car & _car) {
    std::cout << "Car drifted off track." << std::endl;
    //_car.resetToLastValidPosition();
}

void GameScreen::onCarMovedThroughStart(Rac0r::Car & _car) {
    std::cout << "Car moved through start." << std::endl;
}

void GameScreen::onCarStartedFromStart(Rac0r::Car & _car) {
    std::cout << "Car started from start." << std::endl;
}
    

