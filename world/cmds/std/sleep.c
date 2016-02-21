// sleep.c

#include <ansi.h>
#include <command.h>
inherit F_DBASE;

int main(object me, string arg)
{
        object obj, old_target;
        int i;
        object *inv;    
        object where = environment(me);
        
        seteuid(getuid());

        if( !where->query("sleep_room") &&
            !me->query_temp("force_sleep") )
            //mon 12/18/97, allow forced sleep by "keshui chong".
                return notify_fail("这里不是睡觉的地方。\n");

        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能睡觉！\n");
        
        if ((time()-me->query("last_sleep"))<90)
                return notify_fail("你刚睡过一觉, 先活动活动吧。 \n");
        if((!arg)||arg==(string)me->query("id"))
        {
        if (where->query("if_bed"))
        {
                write("你往被中一钻，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                me->set("last_sleep",time());
                me->set_temp("block_msg/all",1);
                message_vision(HIY "$N往被中一钻，不一会便鼾声大作，进入了梦乡。\n" NOR,me);
        }
        else { 
                write("你就地一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                me->set("last_sleep",time());
                me->set_temp("block_msg/all",1);
                message_vision(HIY "$N就地一躺，不一会便鼾声大作，进入了梦乡。\n" NOR,me);
        }

        if (me->query_temp("ridee"))
                me->query_temp("ridee")->set_temp("rider",0);
        me->set_temp("ridee",0);
        me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
        me->set_temp("ride/dodge",0);
        me->disable_player("<睡梦中>");
        me->set_temp("mark/sleep_in_bed",1);

        call_out("wakeup1",random(45 - me->query("con")) + 10, me, where);
        
        return 1;

        }

        if(!objectp(obj = present(arg, where)))
                return notify_fail("你想跟谁一起睡？\n");

        if( !obj->is_character() )
                return notify_fail("？脑袋出毛病了？\n");

        if( !userp(obj) )
                return notify_fail("人家可不愿理你！\n");
        //can't sleep with npc...

        if(me->query("gender")==obj->query("gender"))
                return notify_fail("？对方跟你可是同性呢．．．\n");

        if( !living(obj) )
                return notify_fail(obj->name() + "没法跟你睡了。\n"); 

        if (!where->query("if_bed"))    return notify_fail("就在这里？不太好吧。\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
                return notify_fail("你现在是心有余而力不足。\n");

        if( userp(obj) && (object)obj->query_temp("pending/sleep")!=me ) {
                message_vision(RED "\n$N含情脉脉地对$n说：我．．．\n\n" NOR, me, obj);
                if( objectp(old_target = me->query_temp("pending/sleep")) &&!((string)old_target->query("id")==(string)obj->query("id")))
                        tell_object(old_target, YEL + me->name() + "改变主意不想跟你睡了。\n" NOR);
                me->set_temp("pending/sleep", obj);
                tell_object(obj, YEL "看来" + me->name() +
                "("+(string)me->query("id")+")"+ 
                "很想跟你．．．如果你愿意，请也下一次 sleep 指令。\n" NOR);
                write(YEL "对方正在考虑中．．．\n" NOR);
                return 1;
        }

                message_vision(RED "\n$N冲着$n会心地一笑，点了点头。\n\n" NOR, me, obj);
                
        inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                                REMOVE_CMD->do_remove(me, inv[i]);
        inv = all_inventory(obj);
                for(i=0; i<sizeof(inv); i++)
                                REMOVE_CMD->do_remove(obj, inv[i]);
        
        
        if(me->query("gender")=="男性"){
                tell_object(me, HIY "\n\n你搂着"+obj->query("name")+
                "温软的身体，不由得心醉神迷．．．\n\n\n" NOR);
                tell_object(obj, HIY "\n\n你躺在"+me->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        else{
                tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得心醉神迷．．．\n\n\n" NOR);
                tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
                me->set("last_sleep",time());
                obj->set("last_sleep",time());
                me->set_temp("block_msg/all",1);
                obj->set_temp("block_msg/all",1);
                message_vision(HIY "$N和$n钻入被中，搂在一起睡着了．．．\n\n\n" NOR,me,obj);


        if (me->query_temp("ridee"))
                me->query_temp("ridee")->set_temp("rider",0);
        me->set_temp("ridee",0);
        me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
        me->set_temp("ride/dodge",0);
        if (obj->query_temp("ridee"))
                obj->query_temp("ridee")->set_temp("rider",0);
        obj->set_temp("ridee",0);
        obj->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
        obj->set_temp("ride/dodge",0);
        me->disable_player("<睡梦中>");
        obj->disable_player("<睡梦中>");

        call_out("wakeup2",random(45 - me->query("con")) + 10, me,obj, where);
        call_out("wakeup2",random(45 - obj->query("con")) + 10, obj, me,where);
        
        return 1;

}


void wakeup1(object me,object where)
{
        if(!me) return;

   if (me->query_temp("mark/sleep_in_bed") )
   me->delete_temp("mark/sleep_in_bed");
        me->set("sen",(int)me->query("eff_sen"));
if ((int)me->query("mana") < (int)me->query("max_mana"))
me->set("mana", (int)me->query("max_mana"));

        me->enable_player();

        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        if(interactive(me)){
            object pillow=present("huangliang zhen",me);
            
            if((pillow && pillow->goto_dream(me)) ||
                random(100)==1) {
                if(pillow) pillow->pillow_destruct();
                me->set("dream_place",(string)environment(me));
                me->set_temp("block_msg/all", 0);
                write("\n\n");
                me->move("/d/ourhome/honglou/kat");
                return;
            }
        }
        
        message_vision(HIY "$N一觉醒来，精力充沛地活动了一下筋骨。\n" NOR,me);
        me->set_temp("block_msg/all", 0);
        write("你一觉醒来，只觉精力充沛。该活动一下了。\n");
}

int wakeup2(object me,object slept,object where)
{
        int kee_cost;
        object obj;

   if (me->query_temp("mark/sleep_in_bed") )
   me->delete_temp("mark/sleep_in_bed");
        kee_cost=50+5*((int)me->query("str")-(int)me->query("con"));
        if(kee_cost>(int)me->query("max_kee")/2)        
                kee_cost=(int)me->query("max_kee")/2+1; 

                me->set("sen",(int)me->query("eff_sen"));
                if ((int)me->query("mana") < (int)me->query("max_mana"))
                me->set("mana", (int)me->query("max_mana"));
                me->add("max_atman",1);
                me->add("kee", -kee_cost);      

        me->enable_player();
 
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));

        if(!slept->query_temp("is_bearing") && interactive(me)){
            object pillow=present("huangliang zhen",me);
            
            if((pillow && pillow->goto_dream(me)) ||
                random(100)==1) {
                if(pillow) pillow->pillow_destruct();
                me->set("dream_place",(string)environment(me));
                me->set_temp("block_msg/all", 0);
                write("\n\n");
                me->move("/d/ourhome/honglou/kat");
                return 0;
            }
        }
//      else{
                if(me->query("gender")=="男性"){
                        message_vision(HIY "$N醒了过来，似乎还沉浸在幸福之中。\n" NOR,me);
                        me->set_temp("block_msg/all", 0);
                        write("你醒了过来，似乎还沉浸在幸福之中。\n");
                        return 1;
        }
                else{
                // we add bearing function here. wuliao@xyj Feb. 1997       
                        message_vision(HIY "$N醒了过来，脸上还挂着甜蜜的笑容。\n" NOR,me);
                        me->set_temp("block_msg/all", 0);
                        write("你醒了过来，脸上还挂着甜蜜的笑容。\n");
        //              if (me->query("husband"))
        //                      obj = present ( keys(me->query("husband"))[0], where);
// added by pickle 10-13-97
// sleep with someone other than husband will also give child.
                        obj=slept;
                        if(me->query("max_atman")<40 || 
                                me->query("max_atman")/100 < me->query("child")) 
                        return 1;
                        if (obj!=slept ){
                  if (!obj || !userp(obj)
                  || !find_player(obj->query("id"))) {
                        message_vision(HIY "\n$N似乎觉得腹中一阵颤痛，旋即咬咬牙，弯着腰站了起来。\n"NOR, me);
                        write("\n丈夫都不在，怎么也不能把孩子生下来．．．\n");
                        }
                        else{
                        message_vision(HIY "\n$N似乎觉得腹中一阵颤痛，旋即羞红着脸，咬咬牙站了起来。\n"NOR, me);
                        write("\n怎么会让他撞上了？．．．\n");
                        }
                        me->set("sen", me->query("sen")/2);
                        me->set("kee", me->query("kee")/2);
                        me->set("gin", me->query("gin")/2);
                        return 2;
                        }
                        else
                        {
                        if(obj->query("max_atman")<40 || 
                                obj->query("max_atman")/100 < obj->query("child") ){
                        message_vision(HIY "\n$N忽觉腹中一阵颤动，不过马上又平静下来。\n"NOR,me);
                        return 1;}
                        me->set_temp("is_bearing",1);
                        me->start(100);
                        obj->start(100);
                        message_vision(HIY "\n$N忽觉腹中一阵颤动，赶紧拉住$n的手，柔声说道：要生了! \n" NOR, me,obj);
                        call_out("birth1",15,me,obj);
                        return 3;
                        }
                        
         }
//      } 
       
}

int birth1(object me,object obj)
{
        message_vision(HIY "\n$N已是大汗淋漓，一直都在呼天抢地，双手紧紧扣住$n的手不放。\n"+
         "\n婴儿已经探出了头．．．\n"NOR,me,obj);
        call_out("birth2",15,me,obj);
        return 1;
}


void birth2(object me,object obj)
{
        object baby;
        int number;
        message_vision(HIY "\n「哇」．．．，婴儿出世了！\n"+
"\n$N面色苍白，斜倚在床头，看看孩子满意地露出一丝微笑。\n"NOR, me);
        me->start_busy(1);
        obj->start_busy(1);
        me->set("sen",0);
        me->set("kee",0);
        me->set("gin",0);
        baby=new("/d/changan/playerhomes/npc/baby");
        baby->set("long", baby->query("long")+"这是"+obj->query("name")+"和"+me->query("name")+"的孩子。\n");
        if (random(100)<50){
        baby->set("gender","男性");
        baby->set_name("小"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
        }       
        else{   
        baby->set("gender","女性");
        baby->set_name("小"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
        }
        me->add("child",1);
        obj->add("child",1);
        baby->set("parents",({me->query("id"),obj->query("id")}));
        number=me->query("child");
        me->set("child_"+number+"/gender",baby->query("gender"));
        me->set("child_"+number+"/long",baby->query("long"));
        me->set("child_"+number+"/name",baby->query("name"));
        me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
        me->set("child_"+number+"/parents",baby->query("parents"));
        number=obj->query("child");
        obj->set("child_"+number+"/gender",baby->query("gender"));
        obj->set("child_"+number+"/long",baby->query("long"));
        obj->set("child_"+number+"/name",baby->query("name"));
        obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
        obj->set("child_"+number+"/parents",baby->query("parents"));
        me->delete_temp("is_bearing");
        me->save();
        obj->save();
        //this needs to be put at the last since
        //can only move the baby after it's parameters are set.
        if(!baby->move(environment(me)))
          baby->move(environment(environment(me)));

}       
int help(object me)
{
  write(@HELP
指令格式 : sleep <人物>
 
顾名思义，这个指令是用来睡觉的。
HELP
    );
    return 1;
}



