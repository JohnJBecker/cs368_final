///////////////////////////////////////////////////////////////////////////////
// File Name:      recipe.hpp
//
// Author:         John Becker, Austin Behrens
// CS email:       jbecker@cs.wisc.edu, behrens@cs.wisc.edu
//
// Description:    Header file for the recipe.hpp file
//
///////////////////////////////////////////////////////////////////////////////

#ifndef RECIPE_HPP
#define RECIPE_HPP

#include <vector>
#include <string>
#include "Ingredient.hpp"

class Recipe {
private:
	std::string name;
	std::string directions;
	std::vector<Ingredient> ingredients;
    int numberOfIngredients;
	
public:

    /**
     * @brief empty constructor
     */
	Recipe();

	/**
	 * @brief constructor with parameters passed in
	 *
	 * @param newName name of recipe
	 * @param instructions instructions for recipe
	 * @param ingredients ingredients that are in the recipe
	 */
	Recipe(std::string newName, std::string instructions,
		   std::vector<Ingredient> ingredients);

    /**
     * @brief setter for the name of the recipe
     *
     * @param newName new value for the name
     */
	void setName(std::string newName);
	
	/**
	 * @brief getter for the name of the recipe
	 *
	 * @return the string of the name of the recip
	 */
    std::string getName();
	
	/**
	 * @brief setter for the directions of the recipe
	 *
	 * @param newDirections new value for the directions
	 */
    void setDirections(std::string newDirections);
	
	/**
	 * @brief getter for the directions
	 *
	 * @return the string of the directions for the recipe
	 */
    std::string getDirections();
	
	/**
	 * @brief adds an ingredient to the list of ingredients for the recipe
	 *
	 * @param newIngredient new ingredient for the list
	 */
    void addIngredient(Ingredient newIngredient);
	
	/**
	 * @brief gets the ingredients of the recipe
	 *
	 * @return the vector of ingredients in the recipe
	 */
    std::vector<Ingredient> getIngredients();

	/**
	 * @brief prints out the recipe
	 */
	void printRecipe();
	
};

#endif //RECIPE_HPP