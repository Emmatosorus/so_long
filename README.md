## → Description 📝
A small and chill 2D game written in **C**. You navigate and collect coins. Once you've collected all the coins, you can enter a hut to finish the level. 🏠💰

## → Installation ⚙️
**1 -** Clone the repository:
```
git clone https://github.com/Emmatosorus/so_long.git
```
**2 -** If you want the **full experience** ✨💅:
```
cd so_long/so_long_bonus_dir
make
cd ..
```
**OR**

**2 -** If you prefer a **simpler experience** (less HUD and less map details) 🥺:
```
cd so_long/so_long_dir
make
cd ..
```

## → Running the game 🎮
The different maps are stored in the `levels/` directory

If you chose the **full experience**:
```
./so_long_bonus levels/<the map you want to open>
```
If you chose the **simpler experience**:
```
./so_long levels/<the map you want to open>
```
⚠️ **WARNING** Maps containing the `_bonus` in there name cannot be opened with the simpler experience. ⚠️

## → Create your own maps! 🛠️
So_long is not just a game, it's also a game engine of sorts! ✨

### How to create your map:
**1 -** Create a file with **any** name you want and add **.ber** at the end.

**2 -** Inside the file, create your map following these rules:
  - The map must be **rectangular**.
  - The map must be **enclosed** (surrounded by walls).
  - The map must contain **1 starting position**, **1 exit**, and **at least 1 coin**.
  - The map must be **finishable** (all coins must be accessible). 
      
And this syntax :
  - `0` for an empty space
  - `1` for a wall
  - `C` for a coin
  - `E` for the exit
  - `P` for the player’s starting position
  - `F` for a bramble bush (**ONLY FOR FULL EXPERIENCE MAPS**)
  
If your map doesn't follow a rule, an error message will be displayed in the terminal. 🚨

**3 -** Now you can run the game 🥳
```
./so_long_bonus /path/to/your/map/file
```
or
```
./so_long /path/to/your/map/file
```

## → Controls
- **WASD** to move around 🕹️
- **Shift** to sprint 💨
- **Escape** to exit ❌
- **E** to display the remaining number of coins in the terminal (**ONLY IN THE SIMPLER EXPERIENCE**)

## → Some pictures
![Illustration 1](https://github.com/Emmatosorus/so_long/blob/main/sprites/repo/illustration1.png?raw=true)
![Illustration 2](https://github.com/Emmatosorus/so_long/blob/main/sprites/repo/illustration2.png?raw=true)
![Illustration 3](https://github.com/Emmatosorus/so_long/blob/main/sprites/repo/illustration3.png?raw=true)
