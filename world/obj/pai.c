inherit ITEM;

void create()
{
        set_name("铜牌", ({"tong pai", "pai"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "个");
           set("long", "一个小铜牌，上面还雕着花，写着字．\n");
	set("player", "bula"); 
          set("no_sell", 1);
        }
}


string long()
{
   string msg;

   if(!query_temp("long_1") )
          return query("long");

   msg = "一枚铜牌\n",
   msg += "上写：" + query_temp("long_1") + "\n";

   return msg;
}
string player()
{ 	string msg;
	if(!query("player"))
	return query("player");
	msg = query("player");
return msg;
}
