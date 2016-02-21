//Cracked by Roath
inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("惊天丹", ({"huanhun dan", "dan"}));
        
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗黑呼呼的药丸。\n");
        }
}
int do_eat(string arg)
{
        string *skills;
        mapping all_skills;
        int i;
        if (!id(arg))
             return notify_fail("你要吃什么药？\n");
 else{
        all_skills=this_player()->query_skills();
        if (!sizeof(all_skills))  destruct(this_object());
        skills=keys(all_skills);
        for(i=0;i<sizeof(skills);i++)
        this_player()->set_skill(skills[i],all_skills[skills[i]]*3/2);
        this_player()->add("combat_exp",this_player()->query("combat_exp"));
        this_player()->add("daoxing",this_player()->query("daoxing"));        
        this_player()->add("potential",this_player()->query("potential")-this_player()->query("learned_points"));
        message_vision("$N吃下一颗惊天丹,什么都增加了。\n", this_player());
       destruct(this_object());
        return 1;
        }
}

