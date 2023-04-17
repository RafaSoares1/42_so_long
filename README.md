# so_long

## Purpose

This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements using the MinilibX graphics library.<br />
The project is inspired by the Rick and Morty TV Series.

![Screenshot from 2023-03-28 13-05-49](https://user-images.githubusercontent.com/103336451/228247457-c1c5b34b-4dd5-4608-ba1c-e4c99c5d3372.png)

## MinilibX

The minilibx is a C library used for rendering graphics, primarily used by 42 students. As the name implies, this library is built on top of the X Window System API, to provide a much simpler programming interface suited for beginners. Indeed, no X knowledge is needed at all to render graphics properly using this kind of library.

Here are some websites that can help you better understand this library:<br />
https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx <br />
https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx <br />
https://pulgamecanica.herokuapp.com/posts/mlx-animations <br />

## How to compile?

First we need to download the MinilibX library to our so_long folder:

```sh
wget https://projects.intra.42.fr/uploads/document/document/15283/minilibx-linux.tgz
```

The project is divided in two parts, the mandatory part and the bonus part.

To compile the mandatory part (character movement and item collection) use:

```sh
make 
```
To compile the bonus part use:

```sh
make bonus
```

### Play the game


To run the game, you must choose one of the maps. Example:

```sh
./so_long mandatory/maps/map6.ber
```

Or for the bonus:

```sh
./so_long_bonus bonus/maps/map2.ber
```

### Game Elements

| CHARACTER  | DESCRIPTION |
| ------------- | ------------- |
|   0 |    Floor |
|   1   |   Wall |
|   C   |   Collectible |
|   E |    Exit |
|   P   |   Player |
|   M |    Enemy |


### How to play

The player’s goal is to collect all collectibles present on the map then escape with minimal movement.

|KEYBOARD  | 	ACTION |
| ------- | -------- |
|W, ↑ |	Move up |
|S, ↓ |	Move down |
|A, ← |	Move left |
|D, → |	Move right |
|ESC ⎋ |	Close the game window |

## Gameplay

![so_long](https://user-images.githubusercontent.com/103336451/228253105-d79a344a-2cae-40b5-9d7c-dcc19228d852.gif)

## Final grade

![Screenshot 2023-04-17 at 12-04-49 Intra Projects so_long](https://user-images.githubusercontent.com/103336451/232466789-0a9d6693-8855-4088-a218-db0e36b6d007.png)

