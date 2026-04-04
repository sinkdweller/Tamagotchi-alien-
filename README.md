<p align="center">
  <img src="alien-right-open .png" alt="Demo screenshot" width="300">
</p>

<p align="center">
  <strong>Pocket Man</strong>
</p>

<p align="center">
  A tiny digital companion that lives in your pocket
</p>

<br>

## Overview

**Pocket Man** is a Tamagotchi-style virtual pet built on an ESP32 with a small OLED display.  
It’s designed as a fun project to encourage mindfulness and taking care of yourself!!

Take care of pocketman... take care of yourself

---

## Features

### Core Gameplay
- **Hunger System**
  - Pocket Man gets hungry over time
  - Manually feed it with a small minigame using animated food interactions
    
- **Energy System**
  - Energy decreases naturally
  - Resting (sleep state) restores energy
  - Doing certain activities may decrease energy further

- **Happiness System**
  - Changes based on actions and neglect
  - Affects overall health

- **Annoy System**
  - Overfeeding or neglect increases annoyance
  - Triggers visual emotes
  - Reduces happiness

- **Health System**
  - Tied to all other stats
  - Poor care leads to sickness
  - 0 health will kill your pocket friend
---

### States & Behaviours
- **Sleep**
  - Regenerates energy
  - Slightly improves happiness

- **Exercise**
  - Increases happiness the fastest but:
  - Drains energy faster
  - Increases hunger
    
- **Eating**
  - Interactive feeding system with animated food
  - Press the feed button to interactively feed pocket man and increase fullness + happiness.
  - Randomized sprites have different fullness meters
  - Feed Pocket man too much and it will become slightly bugged, then annoyed, and then angry

- **Idle**
  - Default passive state
  - Poke the Pocket Man to play!

---

### Visual System / additional
- Sprite-based rendering using `Adafruit_GFX`
- OLED display (SSD1351)
- Emote system gives hints to Pocket Friend's state
- (Examples):
  - Sweat 
  - Error 
  - Anger (vein) 
- Pure black is treated as transparent pixels and skipped to draw sprite overlays
---

### Input System
-  3-button interface:
  - Navigate menu (left, right)
  - Select actions
  - Trigger interactions
  - Pressing select will also print Pocket Friend's stat/states to serial monitor
  
---

## Technical Implementation

### Architecture
- Written in **C++ (Arduino/ESP32 environment)**
- Time Management:
  - Managed in system/
  - The program has two "truths" for time management: system time and realtime. System time is used in stat logic such as happiness, fullness, etc. Realtime is maintained for UI rendering purposes, but system time can be sped up / slowed down using TIME_SCALE for easier debugging on tamagotchi behaviour.  
- `littleGuy.*` → core pet logic including state and stat management
- `animatables/` → actions, food, emotes, + private methods for easy frame toggles
- `home_screen/` → UI rendering
- `system/` → time management

---

### Game Loop Design

```cpp
loop():
  - Read input
  - Update state
  - Apply stat rates
  - Render frame
  - Tick stats using delta time
