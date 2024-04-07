# Add Game Library Guide
## :notebook_with_decorative_cover: Introduction
#### :briefcase: Project Explication:

In the Arcade projects you have the possibility to add your own game.

You will be able to play your games in the arcade, to do so you will have to
follow the next steps carefully.

Be attentive it is important!

## The way we do it !

### Basic:

To do this please create your folder at this place "src/games" and named
this repository in lowercase letter by the name of your games for exemples: **"src/games/snake"**.

------------

In order for your game to be added to the arcade you will have to in the **"src/games/CMakeLists.txt"** file.
To do this you just have to go to the end of the file and just do like the other games.

Use the example below:

```bash
## Create the games here "create_game(<game_name>)"
create_game(test_game)
```

Just add the line:
**create_game(...)**

Of course has the place of **"..."** you have to put the name of your game.

:construction: But beware, it is absolutely necessary that the name of the game you put
is the same name as the directory created at the beginning. Otherwise it will not work.

------------

### Let's build it:

Pour cette explication nous partirons du principe que nous voulons rajouter le jeux **Snake** :snake:

#### Provider

To start we will create our SnakeProvider class.
This class is the starting class that means it serves either:

- To create the class of the games that we will see later via this function:

```bash
/**
* @brief Provides a new instance of the game
*
* @return Created game instance
*/
virtual std::shared_ptr<shared::games::IGame> createInstance(void) = 0;
```

Or

- To create the game manifest with all this information via this function:

```bash
/**
* @brief Provides the game manifest
*
* @return Manifest of current game
*/
virtual const GameManifest &getManifest() const noexcept = 0;
```

A manifest looks like this:

```bash
typedef struct {
    std::string name;                   // Name of the author
    std::string email;                  // Public contact email
    std::string website;                // Website of the author (`github`, `gitlab`, etc.)
} Author;

typedef struct {
    const std::string name;             // Name of the game
    const std::string description;      // Description of the game
    const std::string version;          // Version of the game
    const std::vector <Author> authors; // Authors
    const std::string iconPath;         // Path of the icon game
} GameManifest;
```

------------

#### Games

Back to the main, effectively in the provider you aures the possibilities to create
the class of the games that we will see now.

So I suggest you create a class that we will call Snake following our example from the beginning,
this class will be the main class because it will manage everything.

It will heritera the interface: **shared::games::IGame**.

Of course, it will override all the following functions:

```bash
/**
* @brief Compute the game each tick of the program
*
* @param dt Time since last tick (Time in `milliseconds`)
*/
virtual void compute(DeltaTime dt) = 0;
```

This one above serves to recover the time elapsed since the last tick of the game and
so perform certain action like moving or other.

/**
* @brief Get the score of the game
*
* @return The score of the game
*/
virtual const int getScore() const noexcept = 0;

This will be used to return the score to the core which will manage the system of high score.

There are other functions in this interface that I see invite to see here: **"arcade/common/games/IGame.hpp"**

But the most important function remains this:

```bash
/**
* @brief Get map of entities
*
* @return Entities map of the game
*/
virtual const entity::EntitiesMap &getEntities(void) const = 0;
```

This function will be used to send all entities to the core. VOur you surely wonder what an entity is?
Don’t worry, we’ll come back to this right after. But this function is very important because it will allow
to display images, texts and much more.

------------

#### Entities

Finally, as I explained earlier the snake game class to take our example will be able to send entities.

An entity contains components that can be of various nature:

```bash
typedef enum {
      TEXTURE,
      TEXT,
      DISPLAYABLE,
      SOUND,
      COLLIDABLE,
      POSITIONABLE,
      KEYBOARD
    } ComponentType;
```

As you see a component can be a texture, text something that can be displayed or not,
a sound, have a colission, ...

So you understood it for every thing you want to display, play or other,
you will have to create a class that will inherit the interfaces select the components that
you want to see in more detail the interfaces of the different components I you
let us direct you here: **"arcade/common/games/components/"**

If we take the example of our snake, then, for example, there would be a tete entity that would look like this:

```bash
class SnakeHeadEntity : public entity::IEntity {
    public:
        SnakeHeadEntity();
        ~SnakeHeadEntity();

        const components::ComponentsMap &getComponents(void) const noexcept override;
    private:
        components::ComponentsMap _components;
};
```
Of course in **components::ComponentsMap** there would be several class of components like:

The texture component:

```bash
class SnakeHeadDisplayable : public components::ITextureComponent {
    public:
        explicit SnakeHeadDisplayable(const entity::IEntity &entity);
        ~SnakeHeadDisplayable();

        // IComponent
        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;
    ...
```
or even the keyboard component:

```bash
class SnakeHeadKeyboard : public components::IKeyboardComponent {
    public:
        explicit SnakeHeadKeyboard(const entity::IEntity &entity);
        ~SnakeHeadKeyboard();

        // IComponent
        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

        // Keyboard
        void onKeyPress(std::shared_ptr<IGame> ctx,
            shared::games::components::IKeyboardComponent::KeyData key) override;

        void onKeyRelease(std::shared_ptr<IGame> ctx,
            shared::games::components::IKeyboardComponent::KeyData key) override;
    ...
```

------------


### Shared Library

If you wish to have more information about the implementation of the games I suggest you go to the folder
**"common/"** where you will find all the interfaces that will inherit your class. These interfaces are domesticated and explained.
If the common folder does not exist I redirect you to this url: **https://github.com/G-Epitech/MAYBDF-ArcadeShared.git**

