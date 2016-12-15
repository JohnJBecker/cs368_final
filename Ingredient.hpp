///////////////////////////////////////////////////////////////////////////////
// File Name:      ingredient.hpp
//
// Author:         John Becker, Austin Behrens
// CS email:       jbecker@cs.wisc.edu, behrens@cs.wisc.edu
//
// Description:    Header file for the ingredient.hpp file
//
///////////////////////////////////////////////////////////////////////////////

#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

#include <string>

class Ingredient {
private:
	std::string ingredient;
	std::string quantity;

public:

	/**
 	 * @brief empty constructor
 	 */
	Ingredient();

	/**
	 * @brief constructor with new values
	 *
	 * @param ingredient ingredient name
	 * @param quantity the amount of the ingredient is needed
	 */
	Ingredient(std::string ingredient, std::string quantity);

	/**
	 * @brief setter for the ingredient name
	 *
	 * @param newName new value for the name
	 */
	void setIngredientName(std::string newName);

	/**
	 * @brief a getter method to retrieve the ingredient name
	 *
	 * @return the string of the ingredient
	 */
	std::string getIngredientName();

	/**
	 * @brief a setter method for the quantity of an ingredient
	 *
	 * @param newQuantity new value of the quantity string
	 */
	void setQuantity(std::string newQuantity);

	/**
	 * @brief getter method for the quantity value
	 *
	 * @return returns the string of the quantity amount
	 */
	std::string getQuantity();

};

#endif //INGREDIENT_HPP