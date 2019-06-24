# ![caterpillar](res/caterpillar.png) Caterpillars ![caterpillar](res/caterpillar.png)
#### An open-source implementation of the Worms games. Made in C++17.

## Compiling (Linux)
To compile the game, just clone the repo with the command

`git clone https://gitlab.com/Paragoumba/caterpillars.git`.

Then run the following commands:
```bash
cmake -B build
cmake --build build --target Caterpillars -- -j 2
```
Then launch the game with `./build/Caterpillar`.

## Controls
- Use `q` or `d` to move left or right
- Use `z` or `s` to aim up or down
- Press `[space]` to shoot
- Press `[return]` to jump
- The game quits when `[esc]` is pressed

## Licensing
The game and its sources are released under the MIT license. See [LICENSE](LICENSE) for further details.

**Noto is a trademark of Google Inc.** Noto fonts are open source. All Noto fonts are published under the [SIL Open Font
 License, Version 1.1](http://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&id=OFL).