// overview.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *ob;
        int i, m;

        switch(arg) {
                case "user":
                        ob = users();
                        printf("共有 %d 个使用者物件　\n", sizeof(ob));
                        break;
                case "living":
                        ob = livings();
                        printf("共有 %d 个生物(含使用者)物件　\n", sizeof(ob));
                        break;
                case "char":
                        ob = objects( (: $1->is_character() && !clonep($1) :) );
                        printf("共有 %d 种人物物件 master copy 被载入　\n", sizeof(ob));
                        break;
                case "npc":
                        ob = filter_array( livings(),
                                (: $1->is_character() && !userp($1) && clonep($1) :) );
                        printf("共有 %d 个 NPC 物件　\n", sizeof(ob));
                        break;
                case "combat":
                        ob = objects( (: $1->is_fighting() :) );
                        printf("共有 %d 个人物正在战斗状态　\n", sizeof(ob));
                        break;
                case "kill":
                        ob = objects( (: $1->is_killing() && $1->is_fighting() :) );
                        printf("共有 %d 个人物正在性命相搏的战斗状态　\n", sizeof(ob));
                        break;
                case "hunt":
                        ob = objects( (: $1->is_killing() :) );
                        printf("共有 %d 个人物正和其他人物互相仇恨　\n", sizeof(ob));
                        break;
                case "heart beat":
                        ob = objects( (: query_heart_beat :) );
                        printf("共有 %d 个物件的 heart beat 为有效状态　\n", sizeof(ob));
                        break;
                case "virtual":
                        ob = objects( (: virtualp :) );
                        printf("共有 %d 个虚拟物件　\n", sizeof(ob));
                        break;
                case "room":
                        ob = objects( (: function_exists("create_door", $1) :) );
                        printf("共有 %d 个房间　\n", sizeof(ob));
                        break;
                case "special room":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(ROOM) ) ROOM->foo();
                        ob = objects( (: inherits(ROOM, $1) :) );
                        printf("共有 %d 个物件继承标准房间　\n", sizeof(ob));
                        break;
                case "equip":
                        // inherits won't work if master copy got cleaned up.
                        if( !find_object(F_EQUIP) ) F_EQUIP->foo();
                        ob = objects( (: inherits(F_EQUIP, $1) :) );
                        printf("共有 %d 个物件继承标准装备　\n", sizeof(ob));
                        break;
                case "object":
                        ob = objects();
                        printf("共有 %d 个物件被载入　\n", sizeof(ob));
                        break;
                default:
                        return notify_fail("指令格式：overview <topic>\n");
        }
        m = 0;
        i = sizeof(ob);
        while(i--)
                m += memory_info(ob[i]);
        printf("总共使用 %d bytes 记忆体　\n", m);
        if( sizeof(ob) )
                printf("平均每个物件使用 %d bytes 记忆体　\n", m / sizeof(ob));
        return 1;
}

int help()
{
        write(@TEXT
指令格式：overview <主题>

user:           userp()
living:         living()
room:           function_exists("create_door", ob);
TEXT
        );
        return 1;
}



