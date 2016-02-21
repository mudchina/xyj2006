//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("照妖镜", ({"zhaoyao jing", "jing"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                
        set("long",
"一面青色铜制的照妖镜，使天上地下的妖魔鬼怪无处遁形。\n");
        set("material", "steel");
        set("owner_name", "李靖");
          set("owner_id", "li jing");
        set("skill", ([
                        "name": "literate",
                        "sen_cost": 45,
                        "difficulty": 40,
                        "max_skill": 60,
]) );
        }
}
