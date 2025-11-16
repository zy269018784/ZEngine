int http_main(int argc, char** argv);
int ProgressDownloadermain(int argc, char** argv);
void LVGLDemos();
int MindVisionMain(int argc, char** argv);
int ModuleTest(int argc, char** argv);
int MultiMediaTest(int argc, char** argv);
int FreetypeTest(int argc, char** argv);
int MultiMediaTest2(int argc, char** argv);

int NetworkTest(int argc, char** argv);


int WebSocketServerTest(int argc, char** argv);
int WebSocketClientTest(int argc, char** argv);

int ModuleTest(int argc, char** argv)
{
	return WebSocketClientTest(argc, argv);
}