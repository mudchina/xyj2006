//inventory.c

#include <ansi.h>
#include <tomud.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i;
        object *inv, ob;
        mapping count;
        mapping equiped;
        mapping unit;
        string short_name;
        int    total_item;
        object obn;

        string str;
        string *dk;

        if ((wizardp(me) || me->query("couple/child")) && arg)
	{
                ob = find_player(arg);
                if (! ob) ob = find_living(arg);
                if (! ob) ob = present(arg, environment(me));
                if (! wizardp(me) && (! ob || me->query("couple/child") != ob->query("id"))) 
                        return notify_fail("你要察看谁的状态？\n"); 
        }

        if (! ob) ob = me;

        total_item = 0;
        inv = all_inventory(ob);
        if (! sizeof(inv))
	{
                write((ob == me) ? CLEAN1+"目前你身上没有任何东西。\n"
                                 : ob->name() + "身上没有携带任何东西。\n");
                return 1;
        }
        str = sprintf("%s身上带著下列这些东西(负重 %d%%)：\n",
                      (ob == me)? "你" : ob->name(),
                      (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance()),str+=CLEAN1;

	if (ob == me)
	{
	        str += CLEAN1;
	        foreach(obn in inv) 
	                str += ADD1(obn); //By JackyBoy@XAJH 2001/5/6
        }
                        
        count   = ([]);
        unit    = ([]);
        equiped = ([]);

        for (i = 0; i < sizeof(inv); i++)
        {
                short_name = inv[i]->short();
                if (undefinedp(count[short_name]))
                {
                        count += ([ short_name : 1 ]);
                        unit += ([ short_name : inv[i]->query("unit") ]);
                }
                else
                        count[short_name] += 1;

                if (inv[i]->query("equipped"))
                        equiped[short_name] = 1;
                else
                        total_item++;
        }

        if (objectp(ob = ob->query_temp("handing")))
                short_name = ob->short();
        else
                short_name = 0;

        dk = keys(count);
        dk = sort_array(dk, 1);
        for (i = 0; i < sizeof(dk); i++)
        {        
            if (dk[i] == short_name)
                // handing now
                str += HIM "□" NOR;
            else
            if (equiped[dk[i]])
                str += HIC "□" NOR;
            else
                str += "  ";

            if (count[dk[i]] > 1)
                str += chinese_number(count[dk[i]]) + unit[dk[i]];
            str += dk[i] + "\n";
        }

        if (! total_item)
                str += "目前没有携带物品。\n";
        else
                str += "目前携带了" + chinese_number(total_item) +
                       "件物品。\n";

        write(str);
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你(你)目前身上所携带的所有物品。
 
注 : 此指令可以 " i " 代替。
 
HELP );
        return 1;
}
