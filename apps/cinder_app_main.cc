//
// Created by Serena Gong on 5/05/22.
//

#include <iostream>
#include"connect_four_app.h"

void prepareSettings(connect4::ConnectFourApp::Settings* settings) {
    settings->setResizable(false);
}

int main(int argc, char *argv[]) {
    cinder::app::RendererRef renderer(new ci::app::RendererGl);
    cinder::app::AppMac::main<connect4::ConnectFourApp>(renderer, "ConnectFourApp", argc, argv, prepareSettings);
    return 0;
}
