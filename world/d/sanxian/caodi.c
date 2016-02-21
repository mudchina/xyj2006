// edited by mind
inherit ROOM;
void create()
{
  set("short","崖底草地");
  set("long",@LONG
非常令人愉快的草地，柔软的青草，看来就好像是张碧绿的毯子。
明亮的光线中，充满了芬芳的香气。四面枝叶茂密的树林。树木间
还点缀着一些鲜艳的花草，几乎要以为自己突然跌落在仙境里。这
仙境唯一可怕的，就是那无边的静寂，没有风，也没有声音，每一
根草，每一片叶子，都是绝对静止的，看来，竟像是没有丝毫生气。
这可怕的静寂．简直要令人发狂！
这美丽的“仙境”，竟又是块“死地”！
LONG
  );
   set("objects", ([
      
   ]) );  
        set("no_magic",1);
        
        setup();
}

void init()
{
   add_action("do_search", "search");
   add_action("do_look", "look");
   add_action("feeling", "feel");
}

int do_look(string arg)
{
   object me;

   me = this_player();
   if (!arg || (arg != "大树" && arg != "tree"))
      return 0;
   if(me->query_temp("mark/foundtree"))
      tell_object(me, "这株树根粗、很大，叶子特别圆，下半截的树皮，
竟和上半截不同，上半截的树皮粗糙，下半截的树皮却
光滑得很。你早就疑心其中有古怪，这树皮像是常常被
人用手摸的，人为什么要摸(feel)这树皮，显然只有一
个解释：“。。。。这株树必定就是道门。”\n");
        me->set_temp("mark/foundbark", 1);
   return 1;
}

int do_search(string arg)
{
   object me;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if(me->query_temp("mark/foundtree"))tell_object(me, "你在四周的树林里发现一棵大树(tree)。\n");
   if (!arg) {
      if(random(100) < llvl) {
         tell_object(me, "你在四周的树林里发现一棵大树(tree)。\n");
         me->set_temp("mark/foundtree", 1);
         return 1;
      }
      if(!me->query_temp("mark/foundtree")){
      message_vision("$N在四周的树林和草地里不停地查找，满头大汗。\n", me);
      tell_object(me, "你没有发现任何值得疑问的事物。\n");
      
      } 
   }
  return 1; 
   
}



int feeling(string arg)
{
        object obj;
        object me;
                
        if(!arg || arg=="")
        {
                write("你要触摸什么？\n");
                return 1;
        }
        if( arg == "树皮" || arg == "bark" )
        {
        me = this_player();
        if(me->query_temp("mark/foundbark")){
        message_vision("$N跪在草地上，仔细地摸着大树的下半截树皮。\n", me);
        me->start_busy(2);
        call_out("searching",2,me);
        me->stop_busy();
        message("vision","只听“卡嚓”一声，仿佛扣动什么机关，树底裂开一个洞，"+me->name() + "赶紧钻了进去。\n", environment(me),me);
        return 1;
        }
        }

        else
        {
                write("你难道能从"+arg+"上摸出名堂来？\n");
                return 1;
        }

}
int searching(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"shudong");
        message_vision("只听“卡嚓”一声，仿佛扣动什么机关，树底裂开一个洞，$N赶紧钻了进去。\n", me);
        }
        return 1;
}

