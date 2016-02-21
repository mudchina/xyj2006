// 枯骨刀－－〖血书〗1
// pickle 9/8/97
#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

void init();
void dry(object book);
int do_read(string arg);
int do_cut(string arg);
int do_stain(string arg);

void create()
{
        set_name("空白帐本", ({"zhang ben", "zhangben", "book", "shu", "zhang",}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long",
	"一本空白的帐本，跟一般客店里的没什么两样。\n");
        set("material", "paper");
        set("value", 0);
	set("name_recognized", "枯骨刀秘笈");
	set("册", 1);
	set("no_drop", 1);
	set("no_put", 1);
        set("skill", ([
                        "name": "kugu-blade",
                        "exp_required": 10000,
                        "sen_cost": 35,
                        "difficulty": 35,
                        "max_skill": 50,
]) );
        }
	setup();
}

void init()
{
    ::init();
    add_action("do_read", "read");
    add_action("do_read", "study");
    add_action("do_cut", "cut");
    add_action("do_cut", "ge");
    add_action("do_stain", "stain");
    add_action("do_stain", "ran");
    add_action("do_stain", "jin");
}
int do_read(string arg)
{
    object book=this_object(), me=this_player();

    if (!id(arg)) return 0;
    if (!interactive(environment(book)))
    {
        tell_object(me, "什么？\n");
	return 1;
    }
    if (!book->query("stained"))
    {
        message_vision("$N拿起"+book->query("name")+"反复研究了一会儿。\n", this_player());
        tell_object(this_player(), "空白的小册子有什么可看的？\n");
        return 1;
    }
    return 0;
}
int do_cut(string arg)
{
    object weapon, me=this_player();

    weapon=me->query_temp("apply/weapon");
    if (!weapon) weapon=me->query_temp("weapon");
    if (!weapon)
        return notify_fail("拿什么来割？\n");
    if(weapon->query("id") != "bi shou")
        return notify_fail("干嘛？又不是要自杀！还是用匕首吧。\n");
    if (arg != "me" && arg != me->query("id"))
        return notify_fail("你想割谁的血？\n");
    me->receive_wound("kee", random(me->query("str")*me->query("max_kee")/100));
    message_vision("$N拿起手中"+weapon->query("name")+"，在胳膊上割了个小口子。\n", me);
    return 1;
}
int do_stain(string arg)
{
    object book=this_object(),me=this_player();
    if(me->query("eff_kee")>=me->query("max_kee"))
        return notify_fail("还是用自己的血比较好。\n");
    if(!id(arg)) return notify_fail("你要染什么？\n");
    message_vision("$N用伤口的血染红了"+book->query("name")+"。\n", me);
    tell_object(me, book->query("name")+"上渐渐显出了图形和小字。\n");
    remove_call_out("dry");
    call_out("dry", 300, book);
    book->add("stained", 1);
    book->set_name(RED"〖血书〗"NOR, ({"xue shu", "xueshu", "blood book", "book", "shu"}));
    book->set("long",
"一本暗红色的小册子，里面写满了蝇头小字。\n");
    return 1;
}
void dry(object book)
{
    book->delete("stained");
    tell_object(environment(book), book->query("name")+"渐渐干了，又变回了帐本样子。\n");
    book->set_name("空白帐本", ({"zhang ben", "zhangben", "book", "shu", "zhang",}));
    book->set("long",
	"一本空白的帐本，跟一般客店里的没什么两样。\n");
    return;
}
