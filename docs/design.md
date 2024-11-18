# Design philosophy of the keyboard and keymap

The design decisions of this keyboard and my keymap are described in detail below.

## Keyboard/layout

Why base this keyboard layout on crkbd?

We need to have as many keys accessible as possible. However, hand movements have huge consequences for typing speed. So, we need to include as many keys as possible without needing to move the hands, and nothing more. Generally speaking, this means that each finger should not have to move more than one key in any direction. This describes a 3x6 layout for each hand, with 3 keys for each thumb, similar to crkbd. Adding any more keys than that would involve excessive hand movements, sacrificing efficiency.

However, there is still more that can be refined. Given my hand size, I still have trouble reaching the outer top keys of the crkbd (top-left for the left hand, top-right for the right hand). As a result, I still move my hand quite a bit in order to use those keys. There are two ways around this: either place rarely-used keys in those positions, or remove them altogether. In order to have a consistent design philosophy and to force myself to be more efficient, these keys should be removed altogether. This leaves us with a 40 key layout.

Lastly, the column spacing has been meticulously tailored to work well with my hands.

## Keymap

So what about the keymap?

After spending several months tweaking my keymap, trying to find the most efficient design, I have come up with a set of rules that I believe are fundamental to a good keymap. These rules are designed to minimize the number of necessary physical keys, without making typing slower or uncomfortable. 

What do I mean by that specifically? Imagine a keyboard that only has two keys. In order to use the keyboard, you would effectively have to use Morse code. While this would entirely eliminate hand movements, it actually makes efficiency plummet to nearly nothing, since it's such a huge chore to type even simple letters. On the other hand, a full-sized keyboard makes it easy to produce any keycode, by providing a dedicated physical key. However, efficiency is poor due to large, frequent hand movements. Somewhere, there is a middle ground. But, as the number of physical keys decreases, the more clever you have to be about keymap design - a good design combined with a smaller number of keys increases efficiency, while a poor design combined with a smaller number of keys might actually decrease efficiency. Therefore, a reduction in physical keys naturally requires a good keymap design.

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
- For the combos/layering, we have a few things that we need still for common use: shift, enter, ctrl, alt, tab, not to mention every letter and symbol. What if we had _two_ versions of shift? one for caps, and one to change to letters and symbols?
  - we can put almost every letter, symbol, and F key in the same layer. Since we have a width of 12 keys, and the bottom layer is the least accessible, put the F keys down there. Since the middle row is the most accessible, put the number keys under `ASDFGHJKL;`. Fill in the rest with symbols. Start by putting `!@#$%^&*` above `12345678`
  - However, in order to not break the 2-max keypress rule, some keys will be a problem. We can put back tick in the middle left to mirror a normal position. Let's put `+` and `|` above `9` and `0`. We can put `\` on the right middle to mirror its position.
  - That still leaves a few of the most common characters, which we'll save for later...
  - The outer middle keys can act as the secondary shift, while the bottom right and bottom left can act as normal shift. Unfortunately, this means you have to hold down the right middle key in order to type back tick, and you have to hold down the left middle key in order to type `\`.
  - However, since these keys only do something while being held down, we can put other functionality on top. For the left center, we can make a tap trigger tab. For the right center, we can make it a `'`. The bottom right shift can be used as an enter key.
  - parentheses are extremely common. place them on the outer thumb keys
  - put `-` on the inner right thumb key. but when held down, make it alt.
  - put `=` on the inner left thumb key. but when held down, make it ctrl.
  - lastly, we have brackets. We can place them under the parentheses, but on the symbol layer.

