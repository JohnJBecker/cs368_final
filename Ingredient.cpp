///////////////////////////////////////////////////////////////////////////////
// File Name:      ingredient.cpp
//
// Author:         John Becker, Austin Behrens
// CS email:       jbecker@cs.wisc.edu, behrens@cs.wisc.edu
//
// Description:    Class to handle and hold information about an ingredient
//
///////////////////////////////////////////////////////////////////////////////

#include "Ingredient.hpp"

Ingredient::Ingredient(){
    ingredient = "";
    quantity = "";
}

Ingredient::Ingredient(std::string newIngredient, std::string newQuantity){
    ingredient = newIngredient;
    quantity = newQuantity;
}

void Ingredient::setIngredientName(std::string newName){
    ingredient = newName;
}

std::string Ingredient::getIngredientName(){
    return ingredient;
}

void Ingredient::setQuantity(std::string newQuantity){
    quantity = newQuantity;
}

std::string Ingredient::getQuantity(){
    return quantity;
}
