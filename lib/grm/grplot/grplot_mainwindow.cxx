#include "grplot_mainwindow.hxx"

const unsigned int MAXPATHLEN = 1024;

GRPlotMainWindow::GRPlotMainWindow(int argc, char **argv) : QMainWindow()
{
  if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
      auto *w = new QWidget(this);
      QString s;
      std::string kind;
      static char path[MAXPATHLEN];
      std::snprintf(path, MAXPATHLEN, "%s/bin", GRDIR);


      auto *message = new QTextBrowser(w);
      message->setSearchPaths(QStringList(path));
      message->setSource(QUrl("../share/doc/grplot/grplot.man.md"));
      message->setReadOnly(true);
      message->setOpenExternalLinks(true);
      message->setAlignment(Qt::AlignTop);
      if (argc >= 3)
        {
          kind = argv[2];
          std::transform(kind.begin(), kind.end(), kind.begin(), ::toupper);
          if (!message->find(QString(kind.c_str()), QTextDocument::FindCaseSensitively))
            fprintf(stderr, "No plot type with the name %s was found.\n", kind.c_str());
        }
      setCentralWidget(message);
      resize(600, 450);
    }
  else
    {
      grplot_widget_ = new GRPlotWidget(this, argc, argv);
      setCentralWidget(grplot_widget_);
      grplot_widget_->resize(600, 450);
    }

  setWindowTitle("GR Plot");
}

GRPlotMainWindow::~GRPlotMainWindow() = default;
