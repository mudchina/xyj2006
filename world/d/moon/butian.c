// 补天台
// writted by mind 2001/2
inherit ROOM;
void create()
{
        set("short", "女娲补天台");
        set("long", @LONG
这里是昆仑极巅一块高耸的岩壁。地上铺满了一堆又一堆奇形怪状色彩斑斓的
残岩碎石，这些补天石（stone）又熔融在一起，在雪色映照下溢彩流光。许多
求仙好道向佛之人在这里吸取天地日月精华，以证正道。
LONG
        );
        set("butian-force_practice",1);
set("objects", ([ /* sizeof() == 2 */
]));
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"fabao-room",
]));
        set("item_desc", ([
                "stone": "熔融在一起的石头，细细裂缝之间有东西闪闪发光。
你似乎也可以在这里用武器撬（qiao）出远古时代的女娲石。\n"
        ]) );
        
        setup();
}
void init()
{
add_action("do_qiao","qiao");
}
int do_qiao(string arg)
{
object me,weapon;
if(!arg ) return notify_fail("你要用什么武器撬女娲石？\n");
me=this_player();
if(!(weapon = present(arg,me))) return notify_fail("你身上似乎没有这样东西！\n");
if(!weapon->query("weapon_prop")) return notify_fail(weapon->name()+"似乎并不是一种武器！\n");
if(!weapon->query("equipped")) return notify_fail("你并没有将"+weapon->name()+"握在手中。\n");
if(weapon->query("no_give")) return notify_fail("这么宝贵的东西拿来撬石头？太浪费了吧？\n");
message_vision("$N用尽全力，将手中的"+weapon->name()+"插入裂缝中使劲一撬。\n",me);
weapon->unequip();
weapon->set("weapon_prop",0);
weapon->save();
me->reset_action();
message_vision("只听见”铛“的一声，$N手中的"+weapon->name()+"应声而断！\n",me);
weapon->set("name","断掉的" + weapon->query("name"));
weapon->set("value",0);
weapon->set("no_drop",0);
if(random(30))
tell_object(this_object(),"熔融在一起的石头似乎有些松动，裂缝更大了！\n");
else
{
tell_object(this_object(),"一颗小小的五彩石子从裂缝中掉了出来！\n");
weapon = new(__DIR__"obj/butian_stone");
weapon->move(this_object());
}
if(!me->query("m_success/补天石"))
        {
                me->set("m_success/补天石",1);
                me->add("potential",500+random(500));
        }
me->start_busy(2);
return 1;
}

