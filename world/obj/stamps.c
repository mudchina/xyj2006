// stamps.c

inherit ITEM;

void create()
{
	set_name("当票", ({"pawn stamp", "stamp"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
    else  {
	   set("unit", "张");
	   set("long", "一张崭新的空白当票，不知道能不能用。\n");
	   set("value", 0);
	   set("no_sell", 1);
	}
}


string long()
{
   string msg;

   if(!query_temp("long_1") || !query_temp("long_2"))
	  return query("long");

   msg = "兹收到\n";
   msg += "   "+query_temp("long_1")+"\n";
   msg += "   "+query_temp("long_2")+"\n";

   return msg;
}

// remove the pawned item if the stamp is destructed.
// (only when the object is still in the pawnshop box.)
void remove()
{
   object ob=query_temp("file");
   object env;

   if(ob && (!objectp(env=environment(ob)) ||
      env->query("id")=="treasure box")) destruct(ob);
   
   ::remove();
}
