# Design philosophy of the keyboard and keymap

The design decisions of this keyboard and my keymap are described in detail below.

## Keyboard/layout

Why base this keyboard layout on [crkbd](https://github.com/foostan/crkbd)?

We should have as many keys available as possible. However, hand movements have huge consequences for typing speed. So, we need to include as many keys as possible without needing to move our hands, and nothing more. Generally speaking, this means that each finger should not have to move more than one key in any direction. This describes a 3x6 layout for each hand, with 3 keys for each thumb, similar to crkbd. Adding any more keys than that would involve excessive hand movements, sacrificing efficiency.

However, there is still more that can be refined. Given my hand size, I still have trouble reaching the outer top keys of the crkbd (top-left for the left hand, top-right for the right hand). As a result, I still move my hand quite a bit in order to use those keys. There are two ways around this: either place rarely-used keys in those positions, or remove them altogether. In order to have a consistent design philosophy and to force myself to be more efficient, these keys should be removed altogether. This leaves us with a 40 key layout.

Lastly, the column spacing has been meticulously tailored to work well with my hands, as well as the thumb keys.

## Keymap

So what about the keymap?

After spending several months tweaking my keymap and trying to find the most efficient design, I have come up with a set of rules that I believe are fundamental to a good keymap. These rules are designed to minimize the number of necessary physical keys, without making typing slower or uncomfortable. 

What do I mean by that specifically? Imagine a keyboard that only has two keys. In order to use the keyboard, you would effectively have to use a modified Morse code. While this would entirely eliminate hand movements, it actually makes efficiency plummet to nearly nothing, since it's such a huge chore to type even simple letters. On the other hand, a full-sized keyboard makes it easy to produce any keycode, by providing a dedicated physical key. However, efficiency is poor due to large, frequent hand movements. Somewhere, there is a middle ground. But, as the number of physical keys decreases, the more clever you have to be about keymap design - a good design combined with a smaller number of keys increases efficiency, while a poor design combined with a smaller number of keys might actually decrease efficiency. Therefore, a reduction in physical keys naturally requires a good keymap design.

### Observations about the nature of typing

Before diving into what makes a good keymap design, let's first consider some observations about the nature of typing, as well as some flaws that come with trying to create a nice keymap with multiple layers or fancy firmware features.

- Some regions of keys are more accessible than others. In my opinion, this is the order of accessibility (for a crkbd):
  1. keys directly under the thumbs
  2. keys directly under the fingertips (home row)
  3. keys above the home row
  4. outer keys of the thumb row
  5. keys under the home row
  6. bottom two keys of the outside column (for the pinky)
  7. top-right and top-left corner keys
- There are types of keypresses/keycodes that occur much more frequently than others. This is just a guesstimate, but it feels like they have an order of frequency similar to this:
  1. alphabet
  2. space
  3. backspace
  4. common symbols, like dash, quote, tab, period, comma, slash, question mark, parentheses
  5. numbers
  6. other symbols
  7. arrow keys
  8. function keys
- some keys only have a function if you tap them (e.g. letters)
- some keys only have a function if you hold them down (e.g. shift, ctrl)
- some keys have duplicate uses (e.g., numpad has the same use as normal number keys)
- some keys have super niche uses (e.g., scroll lock, caps lock)
- some keys are useful, but are hardly used since they are normally ergonomically inaccessible (e.g. Home, End, Delete)
- any character that shows up on the screen needs to appear immediately (right on keypress, rather than key release, or after a timeout). Otherwise, it feels laggy.
- hard-coded delays in keyboard firmware will almost always slow down typing speed
- overly complex keystrokes/chording will slow down typing speed for the relevant keys
- it should take no more than two keypresses to trigger the keypress of a standard keyboard key (e.g. shift+a to make a capital A) - otherwise, typing will always be slower than a full-sized keyboard
- fancy keys, like media control, can make workflows faster (no clicking around with the mouse necessary).
- ctrl, shift, alt, and meta should be available for use with any letter, number, symbol, or cursor keys (arrows, home, end, etc.)
- in order to prioritize typing (over things like gaming), all letters, numbers, and symbols should be easy to access - meaning, it should require no more than two keypresses for any of these characters.
- There are many features of QMK that seem cool on paper, but hinder efficiency. It's hard to make use of these in a way that doesn't slow down typing speed:
  - leader key - requires too many keypresses to make something happen, or worse, causes delays to characters printing on the screen
  - repeat key - I don't like this feature at all, considering it completely requires you to rewire muscle memory of certain words.
  - auto shift - causes delays to printing characters to the screen
  - space cadet shift - causes delays to printing characters to the screen
  - combos - when this is configured as a simple 2-character combo, it's effectively a temporary layer shift. So it's better, and more organized, to just put that key on a layer. If it's more than a 2-character combo, then it's overly complex, and slows down typing
  - tap dance - causes delays in input, or is basically a layer shift, or is overly complex (if more than 3 key presses)
  - tri layers - shouldn't need to press multiple keys just to shift layers

### Keymap design rules

Considering the above observations, we can assemble a set of rules that will help us design a good keymap.

- Most common characters should be input by the easiest keypresses
- Keys that only function when pressed can be combined with keys that only function when held, preferably if neither one has a visible character association
- keys with duplicate physical keys on a full keyboard should be condensed into one key
- keys with extremely limited use should not be included
- Make useful but inaccessible keys more accessible
- All letters, numbers, and symbols should either be placed on the base layer, or accessible with a single layer shift
- layer shift keys should not be shared by any common visible character keys
- ctrl, alt, meta, space, and backspace should be thumb keys, for continuous accessibility and comfort
- All standard typing characters must be rollable (`A -> B -> ~A -> ~B`). This ensures a fast typing speed. Therefore, no letters can also act as modifier keys.

### Keymap design

Using the above list of rules, we can design a keymap that is much smaller than a full keyboard, but doesn't sacrifice any functionality, vastly improving typing speed and comfort. This is what I have found to work best for my workflow:


- Include all letters on the base layer, and also the standard placement of `;`, `,`, `.`, and `/`.
- Place space on the right center thumb key
- Place backspace on the left center thumb key
- For the combos/layering, we have a few things that we need still for common use: shift, enter, ctrl, alt, tab, not to mention every number and symbol. What if we had _two_ versions of shift? one to act as traditional shift, and one to switch to a Layer 2?
  - we can put almost every number, symbol, and F key in the same layer, which we'll call Layer 2. Since we have a width of 12 keys, and the bottom row is the least accessible, put the F keys down there. Since the middle row is the most accessible, put the number keys under `ASDFGHJKL;`. Then we can put many symbols in the top row. Put `!@#$%^&*+|` above `1234567890`
  - We can put back tick in the middle row far-left column to mirror a normal position. We can put `\` on the right middle to mirror its position.
  - That still leaves `-` and `=` and some other keys like `'` and `tab` - but we'll do something else with those.
  - On Layer 1, the outer middle keys can act as the secondary shift, while the bottom right and bottom left can act as normal shift. Unfortunately, this means you have to hold down the right middle key (activating Layer 2) in order to type back tick, and you have to hold down the left middle key (also activating Layer 2) in order to type `\`.
  - However, since these keys only do something while being held down, we add other functional for tapping. For the left center On Layer 1, we can make a tap be a `tab`. For the right center, we can make it a `'`. The bottom right shift can be used as an enter key. The left shift could be tapped as well, but I've decided it actually is not necessary.
  - parentheses are extremely common. place them on the outer thumb keys
  - put `-` on the inner right thumb key. but when held down, make it `alt`.
  - put `=` on the inner left thumb key. but when held down, make it `ctrl`.
  - lastly, we have brackets and braces. We can place the brackets under the parentheses, but on Layer 2. We can place the brackets under `=` and `-`.
- Let's put cursor control on a Layer 3. The easiest way to activate layers is with thumb keys, and the easiest thumb keys are the centers. Since the backspace key is not visual, we can use it for dual-functionality without defying design constraints. So, holding down backspace will be used to activate Layer 3.
  - Ideally, when activating any of these more exotic layers, a second hand shouldn't be required. Since backspace is on the left hand, all of the cursor controls should be on the left keyboard.
  - Put arrow keys under the most natural fingers: `ESDF`.
  - Under `W`, put `Home`. Under `R`, put `End`. 
  - Under `Q`, put `PgUp`. Under `A`, put `PgDn`
  - I still should be able to access Shift, Ctrl, and Alt, so that I can move the cursor more efficiently. Put shift in the same position as Layer 1 (transparent). Put Ctrl under `Z`. Put Alt under `X`.
- I've found it useful to put other keys and macros on Layer 3, left keyboard.
  - Under `C`, I have a macro for `Ctrl + Shift + PgUp` (move tab left). Under `V`, I have a macro for `Ctrl + Shift + PgDn` (move tab right).
  - Under `T`, I have a macro for `Ctrl + 0` (zoom reset). Under `G`, I have a macro for `Ctrl + +` (zoom in). Under `B`, I have a macro for `Ctrl + -` (zoom out).
  - Under `tab`, I have `Caps Lock`.
- On the right side of the keyboard on Layer 3, I have other commonly used keys and macros.
  - Under `J`, I have `Esc`.
  - Under `K`, I have `Alt + Space` (KRunner).
  - Under `L`, I have `Delete`.
  - Under `;`, I have `~`.
  - Under `Space`, I have `Ctrl + Backspace` (delete word left).
  - All other keys except thumb keys on the right keyboard on Layer 3 is Linux Unicode symbols and emojis.
- Layer 4 is the least-used layer. It primarily includes media controls and QMK settings. I can't activate this one with space, because space is used too frequently, and it's (in a way) visual. It feels laggy to have it used as a layer toggle. Instead, I use the right outside key, `)`, to toggle Layer 4. Much like Layer 3, I should be able to toggle the most important keys with one hand. So, the important keys will be on the right keyboard.
  - Under `J`, I have volume down. Under `K`, I have volume up. Under `L`, I have mute.
  - Under `U`, I have previous track. Under `I`, I have play/pause. Under `O`, I have next track.
  - Under `Y`, I have Screen brightness up. Under `H`, I have Screen brightness down.
  - The left keyboard has many QMK settings, that I will not cover here.
- Lastly, on the base layer, we still need the `Super` key somewhere. It normally won't be used unless it's being held down, and it will often be used in combination with some letter. So, it should go on the thumb row, and it will fit in nicely under `(`, the last key key that isn't already used for dual-purpose (aside from Space).

### Keymap visualized

Here is a visual representation of the keymap.

#### Layer 1

```
      ,-----------------------------.             ,-----------------------------.
      |  Q  |  W  |  E  |  R  |  T  |             |  Y  |  U  |  I  |  O  |  P  |
,-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----.
| Tab |  A  |  S  |  D  |  F  |  G  |             |  H  |  J  |  K  |  L  |  ;  |  '  |
|-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
| Sft |  Z  |  X  |  C  |  V  |  B  |             |  N  |  M  |  ,  |  .  |  /  | S/E |
`-----------------------+-----+-----+-----. ,-----+-----+-----+-----------------------'
                        |  (  | Bks |  =  | |  -  | Spc |  )  |
                        `-----------------' `-----------------'
```

* `Tab`: This also toggles Layer 2.
* `'`: This also toggles Layer 2.
* `Bks`: This also toggles Layer 3.
* `S/E`: This is `Shift` when held, `Enter` when tapped.
* `)`: This also toggles Layer 4.
* `=`: This is `Ctrl` when held, `=` when tapped.
* `-`: This is `Alt` when held, `-` when tapped.
* `(`: This is `(` when tapped, `Super` when held.

#### Layer 2

```
      ,-----------------------------.             ,-----------------------------.
      |  !  |  @  |  #  |  $  |  %  |             |  ^  |  &  |  *  |  +  |  |  |
,-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----.
|  `  |  1  |  2  |  3  |  4  |  5  |             |  6  |  7  |  8  |  9  |  0  |  \  |
|-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
|  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |             |  F7 |  F8 |  F9 | F10 | F11 | F12 |
`-----------------------+-----+-----+-----. ,-----+-----+-----+-----------------------'
                        |  [  |     |  {  | |  }  |     |  ]  |
                        `-----------------' `-----------------'
```

#### Layer 3

```
      ,-----------------------------.             ,-----------------------------.
      | PgU | Hme |  Up | End |  M1 |             |     |     |     |     |     |
,-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----.
|  CL | PgD | Lft | Dwn | Rgt |  M2 |             |     | Esc |  M7 | Del |  ~  |     |
|-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
| Sft | Ctl | Alt |  M4 |  M5 |  M3 |             |     |     |     |     |     |     |
`-----------------------+-----+-----+-----. ,-----+-----+-----+-----------------------'
                        |     |     |     | |     |  M6 | ACT |
                        `-----------------' `-----------------'
```

* `M1`: Zoom reset (Ctrl + 0).
* `M2`: Zoom in (Ctrl + +).
* `M3`: Zoom out (Ctrl + -).
* `M4`: Move tab left (Ctrl + Shift + PgUp).
* `M5`: Move tab right (Ctrl + Shift + PgDn).
* `M6`: Delete word left (Ctrl + Backspace).
* `M7`: KRUnner (Alt + Space).
* `CL`: Caps Lock.
* `~`: Tilde.
* `ACT`: Autocorrect toggle.

#### Layer 4

```
      ,-----------------------------.             ,-----------------------------.
      |     |     |     |     |     |             |  BU |  Pt |  PP |  NT |  M1 |
,-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----.
|     |     |     |     |     |     |             |  BD |  VD |  VU |  MU | CAL |     |
|-----+-----+-----+-----+-----+-----|             |-----+-----+-----+-----+-----+-----|
|     |     |     |     |     |     |             |     |     |     |     |     |     |
`-----------------------+-----+-----+-----. ,-----+-----+-----+-----------------------'
                        |     |     |     | |     |     |     |
                        `-----------------' `-----------------'
```

* `BU`: Brightness up.
* `BD`: Brightness down.
* `Pt`: Previous track.
* `PP`: Play/pause.
* `NT`: Next track.
* `VD`: Volume down.
* `VU`: Volume up.
* `MU`: Mute.
* `M1`: Terminal (Ctrl + Alt + T).
* `CAL`: Calculator.

## Other QMK Features Used for Typing

There are only a couple of special QMK features that I use for typing. One of them is [Caps Word](https://docs.qmk.fm/features/caps_word), and the other is [autocorrect](https://docs.qmk.fm/features/autocorrect).

For Caps Word, you hold down both Shift keys to enable it (of course, it disables itself).

For autocorrect, You can see my custom dictionary in the file list. But also, you will notice on Layer 3, that I have a key for toggling autocorrect on/off.

Another feature I use quite extensively is [Tab-Hold Configuration](https://docs.qmk.fm/tap_hold), which determines what is a key tap and what is a key hold. Configuration involves defining timings and orderings of specific keypresses in such a way that everything feels natural. My setup is described in more detail below.

### [Tapping Term](https://docs.qmk.fm/tap_hold#tapping-term)

Tapping Term is how long it takes for a keypress to be considered "hold" instead of a "tap". Over time, I have found these values to match up with my typing speed quite well:

125 ms:
- `Tab`/Layer2
- `'`/Layer2

150 ms:
- `Bks`/Layer3
- `=`/`Ctrl`
- `-`/`Alt`

200 ms:
- Everything else (default, set by QMK)

### [Hold On Other Key Press](https://docs.qmk.fm/tap_hold#hold-on-other-key-press)

Whether to immediately consider a key _A_ be held down when another key _B_ is pressed while key _A_ is still down, instead of having to wait the tapping term or release _B_ before releasing _A_.

For layer shift keys, this essentially determines whether we are allowing rolling to the next layer (`A B ~A ~B` pattern, where A is layer shift and B is on second layer) or if we need to require a full keypress on that layer (`A B ~B ~A` pattern).

For example, say `Tab` is the layer shift key to layer 2, and say I press `[Tab + A + ~Tab + ~A]`, all within the tapping term during fast typing. If Hold On Other Key Press is enabled for `Tab`, then this would output `1`. But if it is disabled, it would type `\ta`, and if I wanted to type `1`, I would have to press the keys like `[Tab + A + ~A + ~Tab]`.

Because having an apostrophe is a common part of many words, I found it better to have HOOKP disabled for `'`. But I've found numbers more common than tab, so I have it enabled for `Tab`.

The summary of what's enabled/disabled:

Enabled:
- `=`/`Ctrl`
- `Tab`/Layer2
- `Shift`/`Enter`

Disabled:
- `Bks`/Layer3
- `'`/Layer2
- `-`/`Alt`
- Anything else (default)

### [Permissive Hold](https://docs.qmk.fm/tap_hold#permissive-hold)

This is pretty much exactly the same concept as Hold On Other Key Press, but with the additional requirement that _B_ be released before _A_ is released in order to activate _A_'s secondary functionality. So, this describes a `A B ~B ~A` pattern.

For more clarification about these features, the QMK documentation has great [documentation](https://docs.qmk.fm/tap_hold#tap-or-hold-decision-modes) comparing the different modes.

In my configuration, Permissive Hold is enabled for all keys by default, with the exception of the keys that shift to my unicode layers. These keys are `,`, `.`, and `/`. Without Permissive Hold or Hold On Other Key Press enabled, these rely on the user pressing the keys for the entire duration of the tapping term. This prevents accidental layer shifts to layers that I don't use very often. 

Note, that in a Tap-hold configuration, the least-restrictive mode will logistically take precedent. Hold On Other Key Press is less restrictive than Permissive Hold, which is less restrictive than the default Tapping Term. You'll notice that Permissive Hold is effectively enabled for all HOOKP-enabled keys. But since HOOKP is less restrictive that PH, it will take precedent.
