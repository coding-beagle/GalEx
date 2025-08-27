# Space Economy Simulation

The aim of this repo is to create a somewhat emergent space economy simulation game - a.la Dwarf Fortress but in space.

## The rules

The game board is an arbitrary grid of nodes that represent solar systems. Each solar system has a number of entities inside.

An entity is defined as a resource producer or consumer. This could be a highly advanced space manufacturing station that consumes highly advanced intermediates in order to produce luxury goods, or it could be an asteroid mining operation that supplies raw ores. It could be a farming planet with low development that provides food to its neighbours.

The idea is that the game board is initialised with a random set of parameters, e.g. each system and entity with a different specialisation, etc.

A number of trading corporations seek to distribute and move goods between systems and entities. You play as one of them.

Beware! Pirate entities create black market areas and areas of high trading risk. This could shoot up the price of goods if you choose to trade in this area, but could also mean a higher risk on losing trading vessels.

## The aim

There isn't much to do other than to explore how your actions can impact the galaxy around you. You could choose to be a cunning business empire, out-competing other trade companies on the price of luxury goods, or you could choose to serve an under represented community of aliens.

Part of the fun will be in impulse responses - the game is a big cause and effect engine.

## Technical details

The game is written in C via Raylib.

Each entity has these parameters:

- Development Index (0.0 - 1.0) : A measure of how developed the entity is. More developed entities want more luxury goods, are less capable of manufacturing and growing their own food.
- Raw resource abundance:
  - A list of (0.0 - 1.0) per resource that can be harvested from the entity. E.g. a tropical farm world might have 1.0 abundance on raw food ingredients, a mining world has 1.0 abundance on ores.
- Population (int):
  - A scalar / multiplier for raw resource abundance. Each number could represent 1,000,000 actual people, etc.
- Resource consumption:
  - A list of (0.0 - 1.0) per resource that the entity needs.
  - Could be scaled by population.
- Wealth (int)
  - An arbitrary number of currency that represents the entity's ability to purchase goods.

Each entity will seek to match its resource consumption through trade, using its wealth to buy and sell from traders.

Supply and demand laws apply - if an underserved system is in need of resources, they are willing to pay more than the market rate, and if there's a high supply, then prices will be low.

Pirate entities seek to plunder trade ships. Trade ships moving into areas of high piracy could be at risk of losing cargo - or getting destroyed. Send a combat escort to ensure goods reach places - but these will cost money!

