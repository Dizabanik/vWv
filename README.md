# vWv (.sh(.c))
## vanilla Wondering virtual shell script(written in C)
## Welcome to vWv! 🌟

Hey there, welcome to vWv - your cozy command-line companion! vWv is a snug little application written in C that's here to make your command-line experience warm and delightful. It fetches commands from URLs and executes them for you, like a trusted friend lending a helping hand!

## Getting Started 🚀

Getting started with vWv is as easy as sipping a cup of hot cocoa on a chilly day.

**Run**:
```bash
git clone https://github.com/Dizabanik/vWv.git ; cd vWv ; sudo mv vWv /usr/local/bin/ ; cd ../ ; rm -rf vWv ; chmod +x /usr/local/bin/vWv
```
This will automatically install the app into /usr/local/bin/ and remove the directory created by git clone

## Usage 🛠️

Using vWv is a breeze. Just open your terminal and type:

```
vWv [link]
```

Replace `[link]` with the URL of the command you want to execute. vWv will fetch it for you and work its magic!

To install one of my projects easily, you can use:
```bash
vWv [project name]
```

### Example ✨

```
vWv https://example.com/script.sh
```

And for my projects:

```bash
vWv fissure
```
## Features 🌈

vWv comes with some delightful features to make your command-line experience even cozier:

- **Dynamic Fetching**: Relax as vWv fetches commands dynamically from URLs using `wget`.
- **Instant Execution**: Watch your commands come to life as vWv executes them with lightning speed using `execl`.
- **Easy to use for your own projects and easy interface to install my**
- **Open source**: use `vWv.sh.c` and `vWv.sh.h` to include it into your project
- **Error Handling**: Don't fret about getting lost. vWv will guide you with error messages if something goes amiss.
