# FUSE Productivity

With the rise of modern technology, people are spending more and more time on their computers and phones. FUSE Productivity believes in moderation; too much screen time is not a good thing.

So how can we help people get off their computers? FUSE Productivity proposes an answer: hide every file. These aren't just the files you can open in Microsoft Word. We hide every file in your home directory. After all, if you can't use your computer, you're going to reduce your screen time.

## Installation

FUSE Productivity requires using FUSE version >= 3.1. Once you have that installed, download this repository, and simply run:

```
gcc -Wall work_mode.c `pkg-config fuse3 --cflags --libs` -o work_mode
./work_mode ~
```

Once you've enjoyed your time off your computer, you can restore your files by typing:

```
sudo umount ~
```

As an added benefit, you can replace the home directory (`~`) with any other directory to hide the files in that directory.
