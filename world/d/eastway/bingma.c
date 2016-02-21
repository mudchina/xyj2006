// create by snowcat.c 4/20/1997
// room: /d/eastway/bingma.c

inherit ROOM;

void create ()
{
  set ("short", "兵马俑阵");
  set ("long", @LONG

你来到一个巨大的兵马俑阵中，天高云阔，成千上万个栩
栩如生的兵马俑排列成几十路纵队，仿佛正在从四面八方
呼啸而来，你不禁被这个宏伟的场面惊倒。

LONG);

  set("exits", ([
        "west"       : __DIR__"shihuang",
      ]));
  set("objects", ([ /* sizeof() == 1 */
        __DIR__"obj/bingma" : 9,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init()
{
        add_action("do_zha", "bomb");
}

int do_zha()
{
        object me, *inv;
        int i,j;
        object exp;
        
        me = this_player();
        j = random(800);

        if( !me->query_temp("mark/始皇陵"))

        return 0;
if(!wizardp(me))  return 0;
        inv = all_inventory(me);
                       for(i=0; i<sizeof(inv); i++)
                {
                                
                        if( (int) inv[i]->query("explosive") )
                                exp = inv[i];
                }
        if( !exp) 
        {
        tell_object(me,"你没有烟炮．\n");
        return 1;
        }

        message_vision("$N点燃了手中的"+exp->name()+"．．．
一道孔雀开屏般灿烂夺目的光芒映花了$N的眼睛，只听得一声滔天巨响＂轰＂，炸出
一个金砖来。原来哪吒给的烟炮是孔雀山庄秘制的火器，用的可是霹雳堂的火药！\n", me, exp);
        if(!me->query("m_success/金砖"))
        {
                me->set("m_success/金砖",1);
                me->add("potential",j+500);
                tell_object (me,"你识破图纸，炸出金砖，得到了"+chinese_number(j+500)+"点潜能！\n");
        }
        destruct(exp);
        tell_object(me, "金砖一闪，飞进了你的身体里，你好象悟得了什么。\n");
        me->set_temp("mark/始皇陵",0);
                        
        return 1;

}





