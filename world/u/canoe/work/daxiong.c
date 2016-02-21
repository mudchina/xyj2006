// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "大雄宝殿");
  set ("long", @LONG

大雄宝殿里金碧辉煌紫气瑞瑞，根根玉柱雕麒麟，殿窗是金钉
银檐，殿顶亦上是金银鸳鸯双双对对，正中有一白玉玛瑙莲花
台。南边有一殿门通往后殿，东西边各有一偏门。

LONG);
  
  set("exits", ([
         "north"   : __DIR__"chanfang",
         ]));
  set("objects", ([
        __DIR__"zhongkui" : 1,
     ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init()
{
    add_action("do_drop", "drop");
    add_action("do_get", "get");
}

int do_drop(string arg)
{
   object me=this_player();
   object obj;
   
   if( !arg ) return 0;
      
   if( !objectp(obj = present(arg, me)) )
          {  tell_object(me,"你身上没有这样东西。\n");
             return 1;
          }
  
   if ( me->query("canoetask/kind") != "擒")
          {  tell_object(me,"钟馗对你说道：“不要在这么乱丢垃圾。”\n");
             return 1;
          }
          
    if( !obj->is_character() )
           {  tell_object(me,"钟馗对你说道：“不要在这么乱丢垃圾。”\n");
             return 1;
          }
               
    else {    if( obj->is_corpse() )
                   {  tell_object(me,"钟馗对你说道：“不要在这么乱丢垃圾。”\n");
                      return 1;
                   }
                   
    	      if( obj != me->query("canoetask/guai") )
                   {   tell_object(me,"钟馗对你说道：“我没有叫你擒此怪回来。”\n");
                       return 1;
                   }
          
               call_out ("accomplish",2,me,obj);
               return 0;
          }
}      

void accomplish(object me, object obj)
{
      if(!living(obj))
	{tell_room(this_object(),"几个金刚把"+obj->name()+"押了下去。\n\n");
	 destruct (obj);
	 me->set("canoetask/accomplish",1);
	 me->set("canoetask/end_time",time());
	 me->delete("canoetask/get");
        }
       else return;
}


int do_get(string arg)
{
	string from;
	object me = this_player();
	object env;
	
	if( !arg ) return 0;
		
	if( sscanf(arg, "%s from %s", arg, from)==2 )
	    {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return 0;
		if(env->is_character() && !living(env))
		      {  tell_object(me,"钟馗对你摇了摇头。\n");
                         return 1;
                      }
            }
	
	else {
		env = present(arg, environment(me));
		if(env->is_character() && !living(env))
	              {  tell_object(me,"钟馗对你摇了摇头。\n");
                         return 1;
                      }
	     }
	         	
	return 0;
}		



