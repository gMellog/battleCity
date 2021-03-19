BattleCity reborn plan
1. Implement Bullet
	a) Bullet spawn
	b) Bullet should blow up when overlapped with something that can destroy otherwise dissapear
	c) Bullet animation during fly will be in Tick
	Typical way of shoot bullets:
	Create it: get Game, add it on map in specific place, and that's all everything other will be processed in constructor
	This will be bind on F key

	Bullet Overlap:
	1. Wall - dissappear
	2. Brick - blow up
	3. Stone - dissappear or blow up 
	All of that behaviors will be received from other objects(will be checked by myself)

	1. Get all overlap objects
	2. Try overlap with them
	3. Got something with what i can overlap
	4. Overlap(): return true or false.
	5. If we can overlap, then we return back to 2 step
	6. Otherwise blow up or just dissappear - we should check object id somehow
	 
2.  Implement Brick
3.  Implement Stone
4.  Implement CharacterBase
5.  Implement first level Map, Player should be capable to move around, shoot something, kill own base.
6.  Implement special enemies, those are should be based on their level, all of them will have their default behavior but when 5 - 10 seconds are passed they got special behavior,
their own special purpose(this will be something like clean some way into player base, find player and kill him, just go and clean all bricks cause you don't like it) that is for first level

*** Player should have 3 lives, there should be some easy menu just for case if you want to pause that for a movement, and we need some stats after game, or you can left game, eveyrthing that you've done will be saved, like in old games it can be based on your name
Hey idea: hm, could we make some other ways how could enemy tanks to win ? They could beat player in score table so,
There will be some level where your base become surrounded with stones and you will have to survive around 1 min


Levels:
1. Introduction, just kill enemies
2. Kill enemies and don't let them go through special place(30% of screen and etc)
3. Do not kill any enemy you should clear more bricks than them, if you kill an enemy you lost
4. You got a message that enemy has some special weapon that can change everything on field, it's big gun(think about name), so you attack enemies's camp and steal their tank.
After that you are on their base, so you look like them, shoot like they are, smells like they are, you are grey fucking tank that searches big gun. Finally you didn't find it, it was just a trap.
5. You have met big mommy tank, it's really big ass tank with 5 guns and could spawn enemy tanks around.

Game should be playable for 1 hour or 1 and half 
