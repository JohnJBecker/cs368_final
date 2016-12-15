///////////////////////////////////////////////////////////////////////////////
// File Name:      recipe.cpp
//
// Author:         John Becker, Austin Behrens
// CS email:       jbecker@cs.wisc.edu, behrens@cs.wisc.edu
//
// Description:    Class to handle and hold information about a recipe
//
///////////////////////////////////////////////////////////////////////////////

#include "Recipe.hpp"
#include "Ingredient.hpp"
#include <vector>
#include <iostream>

Recipe::Recipe(){
	Recipe::numberOfIngredients = 0;
}
	
Recipe::Recipe(std::string newName, std::string instructions,
               std::vector<Ingredient> ingredients){
    Recipe::name = newName;
    Recipe::directions = instructions;
    Recipe::ingredients = ingredients;
    Recipe::numberOfIngredients = 0;
}
	
void Recipe::setName(std::string newName){
    Recipe::name = newName;
}

std::string Recipe::getName(){
	return Recipe::name;
}

void Recipe::setDirections(std::string newDirections){
    Recipe::directions = newDirections;
}

std::string Recipe::getDirections(){
	return Recipe::directions;
}

void Recipe::addIngredient(Ingredient newIngredient){
    ingredients.push_back(newIngredient);
    numberOfIngredients++;
}

std::vector<Ingredient> Recipe::getIngredients(){
	return ingredients;
}

void Recipe::printRecipe(){
    std::cout << "####################################" << std::endl;
    std::cout << "Recipe:" << std::endl;
    std::cout <<  name << std::endl;
    std::cout << "Instructions" << std::endl;
    std::cout << directions << std::endl;
    std::cout << "Ingredients" << std::endl;

    std::vector<Ingredient>::iterator it2;
    int count = 1;
    for(it2 = ingredients.begin(); it2 < ingredients.end();
        it2++) {
        std::cout << count << ":" << std::endl;
        std::cout << it2->getIngredientName() << std::endl;
        std::cout << it2->getQuantity() << std::endl;
        count++;
    }
    std::cout << "####################################" << std::endl;
}
