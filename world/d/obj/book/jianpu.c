// jianpu.c	青莲剑谱

inherit ITEM;

void create()
{
  set_name("〖青莲剑谱〗", ({ "jian pu", "shu", "book" }));
  set_weight(600);
  if( clonep() )
	set_default_object(__FILE__);
  else {
	set("unit", "本");
	set("long", "这是一本基本剑法的图解，书角已经有些残破了。\n");
	set("value", 100);
	set("material", "paper");
	set("skill", ([
		"name":		"sword",	// name of the skill
		"exp_required":	1000,		// minimum combat experience required
						// to learn this skill.
		"sen_cost":	30,		// gin cost every time study this
		"difficulty":	30,		// the base int to learn this skill
						// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	90,		// the maximum level you can learn
						// from this object.
		]) );
	}
}
