//
// Created by fatzzx on 23/06/23.
//

#ifndef DISCORD_BOT_PING_H
#define DISCORD_BOT_PING_H

#include "discord_bot.h"

void handlePingCommand(const dpp::slashcommand_t& event){
    event.reply("Pong !");
}

#endif //DISCORD_BOT_PING_H
