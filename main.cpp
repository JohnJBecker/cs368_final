///////////////////////////////////////////////////////////////////////////////
// File Name:      main.hpp
//
// Author:         John Becker, Austin Behrens
// CS email:       jbecker@cs.wisc.edu, behrens@cs.wisc.edu
//
// Description:    Main class for cs368 recipe book project
//
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Recipe.hpp"
#include "Ingredient.hpp"

int main(){

    std::vector<Recipe> recipeBook;

    std::ifstream inFile ("RecipeBook.txt");
    // Populates the recipe book if there is a recipe book
    // already in the directory
    if(inFile.is_open()){

        // variables to hold temp values for recipe
        std::string line;
        std::string instructions;
        std::string name;
        std::string ingredientName;
        std::string ingredientAmount;
        std::vector<Ingredient> tmpIngredients;

        // If the input file isn't formatted correctly
        // print error message and exit
        int badRecipe = 0;

        // used when populating the ingredients list
        // file goes between name and amount
        bool nameAmountFlop = true;

        // Loops through the input file and populates the recipe book
        while(std::getline(inFile, line) && badRecipe == 0){
            if(line == "Recipe"){
                if(std::getline(inFile, line)){
                    name = line;
                } else{
                    badRecipe = 1;
                }
            } else if(line == "Instructions"){
                if(std::getline(inFile, line)){
                    instructions = line;
                } else{
                    badRecipe = 1;
                }
            } else if(line == "Ingredients"){
                bool gotAllIngredients = false;
                // Can have multiple ingredients so loop until
                // the endOfRecipe flag
                while(!gotAllIngredients){
                    if(std::getline(inFile, line)){
                        if(tmpIngredients.size() > 1000){

                        }
                        if(line == "endOfRecipe"){
                            gotAllIngredients = true;
                        } else{
                            if(nameAmountFlop){
                                ingredientName = line;
                                nameAmountFlop = false;
                            } else {
                                ingredientAmount = line;
                                // We have both the ingredient name and amount
                                // so create a tmp object and add to the list
                                // of ingredients
                                Ingredient tmp(ingredientName,
                                               ingredientAmount);
                                tmpIngredients.push_back(tmp);
                                nameAmountFlop = true;
                            }
                        }
                    } else{
                        badRecipe = 1;
                    }
                }

                if(!nameAmountFlop){
                    badRecipe = 1;
                }

                // Create a tmp recipe and add it to our recipe book
                Recipe newRecipe(name, instructions, tmpIngredients);
                recipeBook.push_back(newRecipe);

                // Clear out the ingredients list for a new recipe
                tmpIngredients.clear();
            }
        }
        inFile.close();

        if(badRecipe == 1){
            std::cout << "ERROR: recipe book file not formatted "
                    "correctly, exiting.." << std::endl;
            exit(1);
        }
    }

    std::string userInput;
    // Console app portion
    while(true) {

        std::cout << "Select command by entering corresponding "
                "number:" << std::endl;
        std::cout << "1 Enter new recipe" << std::endl;
        std::cout << "2 Display recipes" << std::endl;
        std::cout << "3 Save and exit" << std::endl;

        getline(std::cin, userInput);

        if(userInput == "1"){

            std::string recipeName;
            std::string recipeInstructions;
            std::string ingredientName;
            std::string ingredientAmount;
            std::vector<Ingredient> recipeIngredients;
            bool stillAddingIngredients = true;

            // get the name
            std::cout << "Enter name of new recipe:" << std::endl;
            getline(std::cin, recipeName);
            // get the instructions
            std::cout << "Enter cooking instructions for new recipe:"
                      << std::endl;
            getline(std::cin, recipeInstructions);

            // loop while user is adding ingredients
            while(stillAddingIngredients){
                std::cout << "Add another ingredient to "
                        "the recipe? Y/N" << std::endl;
                getline(std::cin, userInput);
                if(userInput == "y" || userInput == "Y"){

                    std::cout << "Enter ingredient name:" << std::endl;
                    getline(std::cin, ingredientName);

                    std::cout << "Enter ingredient quantity:" << std::endl;
                    getline(std::cin, ingredientAmount);
                    // create a new ingredient and add to tmp list
                    Ingredient tmpIngredient(ingredientName, ingredientAmount);
                    recipeIngredients.push_back(tmpIngredient);
                } else if(userInput == "n" || userInput == "N"){
                    stillAddingIngredients = false;
                } else{
                    std::cout << "Please enter y or n" << std::endl;
                }
                // create new recipe with the information entered by the user
                if(userInput == "n" || userInput == "N") {
                    Recipe tmpRecipe(recipeName, recipeInstructions,
                                     recipeIngredients);
                    recipeBook.push_back(tmpRecipe);
                }
            }
        } else if(userInput == "2"){
            std::vector<Recipe>::iterator it;
            // loop through the recipe and print them out
            for(it = recipeBook.begin(); it < recipeBook.end(); it++) {
                it->printRecipe();
            }
        } else if(userInput == "3"){

            // open output file
            std::ofstream outFile ("RecipeBook.txt");
            if(outFile.is_open()){
                // If file can be opened start writing out info
                std::cout << "Saving and exiting.." << std::endl;
                std::vector<Recipe>::iterator it;
                for(it = recipeBook.begin(); it < recipeBook.end(); it++) {
                    // write out name
                    outFile << "Recipe" << std::endl;
                    outFile << it->getName() << std::endl;
                    // write out instructions
                    outFile << "Instructions" << std::endl;
                    outFile << it->getDirections() << std::endl;
                    // write out ingredients
                    outFile << "Ingredients" << std::endl;
                    std::vector<Ingredient> ingredients = it->getIngredients();
                    std::vector<Ingredient>::iterator it2;
                    // write out each ingredient
                    for(it2 = ingredients.begin(); it2 < ingredients.end();
                        it2++) {
                        outFile << it2->getIngredientName() << std::endl;
                        outFile << it2->getQuantity() << std::endl;
                    }
                    // indicate the end of a recipe
                    outFile << "endOfRecipe" << std::endl;
                }
                outFile.close();
            } else{
                std::cout << "ERROR: could not save recipe book, exiting.."
                          << std::endl;
            }

            exit(0);
        } else{
            std::cout << "ERROR: invalid command" << std::endl;
        }

    }
}
