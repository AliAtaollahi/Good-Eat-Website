#include "MainObjects/InterFace.hpp"
using namespace std;
void Interface::serverPages(MyServer &server) {
  server.get("/", new ShowPage("static/htmlFiles/main.html"));
  server.get("/login", new ShowPage("static/htmlFiles/login.html"));
  server.get("/signup", new ShowPage("static/htmlFiles/signup.html"));
  server.get("/homeUserHTML", new ShowPage("static/htmlFiles/homeUser.html"));
  server.get("/homeChefHTML", new ShowPage("static/htmlFiles/homeChef.html"));
  server.get("/about", new ShowPage("static/htmlFiles/about.html"));
  server.get("/aboutUser", new ShowPage("static/htmlFiles/aboutUser.html"));
  server.get("/createRecipe", new ShowPage("static/htmlFiles/createRecipe.html"));
  server.get("/showRecipeHTML", new ShowPage("static/htmlFiles/showRecipe.html"));
  server.get("/addShelf", new ShowPage("static/htmlFiles/addShelf.html"));
  server.get("/myShelvesHTML", new ShowPage("static/htmlFiles/myShelves.html"));
  server.get("/shelveRecipesHTML", new ShowPage("static/htmlFiles/shelveRecipes.html"));
  server.get("/filters", new ShowPage("static/htmlFiles/filters.html"));
}
void Interface::serverCss(MyServer &server) {
  server.get("/main.css", new ShowFile("static/cssFiles/main.css", "text/css"));
  server.get("/login.css", new ShowFile("static/cssFiles/login.css", "text/css"));
  server.get("/signup.css", new ShowFile("static/cssFiles/signup.css", "text/css"));
  server.get("/home.css", new ShowFile("static/cssFiles/home.css", "text/css"));
  server.get("/homebasic.css", new ShowFile("static/cssFiles/homebasic.css", "text/css"));
  server.get("/createRecipe.css", new ShowFile("static/cssFiles/createRecipe.css", "text/css"));
  server.get("/showRecipe.css", new ShowFile("static/cssFiles/showRecipe.css", "text/css"));
  server.get("/addShelf.css", new ShowFile("static/cssFiles/addShelf.css", "text/css"));
  server.get("/myShelves.css", new ShowFile("static/cssFiles/myShelves.css", "text/css"));
  server.get("/filters.css", new ShowFile("static/cssFiles/filters.css", "text/css"));
}
void Interface::serverJS(MyServer &server) {
  server.get("/basic.js", new ShowFile("static/jsFiles/basic.js", "text/js"));
  server.get("/error.js", new ShowFile("static/jsFiles/error.js", "text/js"));
  server.get("/content.js", new ShowFile("static/jsFiles/content.js", "text/js"));
  server.get("/homebasic.js", new ShowFile("static/jsFiles/homebasic.js", "text/js"));
  server.get("/homeUserbasic.js", new ShowFile("static/jsFiles/homeUserbasic.js", "text/js"));
  server.get("/showRecipe.js", new ShowFile("static/jsFiles/showRecipe.js", "text/js"));
  server.get("/myShelves.js", new ShowFile("static/jsFiles/myShelves.js", "text/js"));
  server.get("/filters.js", new ShowFile("static/jsFiles/filters.js", "text/js"));
}
void Interface::serverHandlers(MyServer &server) {
  server.post("/loginpage", new LoginPageHandler(cr));
  server.post("/login", new LoginHandler(cr));
  server.post("/signuppage", new SignupPageHandler());
  server.post("/signup", new SignupHandler(cr));
  server.get("/homeChef", new homeChefHandler(cr));
  server.post("/createRecipePage", new CreateRecipePageHandler());
  server.post("/createRecipe", new PostRecipeHandler(cr, &server));
  server.post("/deleteRecipe", new DeleteRecipeHandler(cr));
  server.get("/homeUser", new homeUserHandler(cr));
  server.get("/showRecipeForm", new ShowRecipeFormHandler(cr));
  server.post("/showRecipeForm", new RecipeFormPageHandler(cr));
  server.post("/RatingHandler", new RatingHandler(cr));
  server.post("/putRecipeInShelveHandler", new PutRecipeInShelveHandler(cr));
  server.post("/addShelf", new AddShelfHandler(cr));
  server.get("/myShelves", new myShelvesHandler(cr));
  server.post("/shelveRecipes", new ShelveRecipes(cr));
  server.post("/filtersPage", new FiltersPage());
  server.post("/filters", new FiltersHandler(cr));
  server.post("/deleteFilters", new DeleteFiltersHandler(cr));
}
void Interface::serverImages(MyServer &server) {
  server.get("/icon.jpg", new ShowImage("static/images/icon.jpg"));
  server.get("/seen.png", new ShowImage("static/images/seen.png"));
  server.get("/unseen.png", new ShowImage("static/images/unseen.png"));
  server.get("/chef.jpg", new ShowImage("static/images/chef.jpg"));
  server.get("/food.jpg", new ShowImage("static/images/food.jpg"));
  server.get("/add.png", new ShowImage("static/images/add.png"));
  server.get("/delete.png", new ShowImage("static/images/delete.png"));
  server.get("/exit.png", new ShowImage("static/images/exit.png"));
  server.get("/filters.png", new ShowImage("static/images/filters.png"));
  server.get("/form.jpg", new ShowImage("static/images/form.jpg"));
  server.get("/send.png", new ShowImage("static/images/send.png"));
  server.get("/shelf.png", new ShowImage("static/images/shelf.png"));
  server.get("/rating.png", new ShowImage("static/images/rating.png"));
  server.get("/settings.png", new ShowImage("static/images/settings.png"));
}