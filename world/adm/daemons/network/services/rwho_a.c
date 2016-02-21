/*
 * File    : remote_a.c
 * Creator : ken@mud.szptt.net.cn
 * When    : 98-1-15
 *
 * This protocol is used to send a intermud emote request.
 */
#define DEBUG "debug"
#undef DEBUG


#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

void create() {
    seteuid(ROOT_UID);
    set("channel_id", "ÍøÂ·ÆµµÀ¾«Áé(remote_a)");
}

void incoming_request(mapping info)
{
    object ob;

    if( !ACCESS_CHECK(previous_object())) return;

    if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"])) {
        if (info["NAME"] == Mud_name()) return ;
        if (!DNS_MASTER->dns_mudp(info["NAME"]))
            PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
        if (!(ob = find_player(lower_case(info["ASKWIZ"])))) return ;
        tell_object(ob, info["RWHO"]);
    }
}

