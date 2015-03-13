#include <stdio.h>
#include <PDFDoc.h>
#include <PDFDocFactory.h>
#include <Catalog.h>

int main(int argc, char *argv[]) {
  PDFDoc *doc;
  GooString *fileName;
  GooString *ownerPW, *userPW;

  if (argc != 2) {
    fprintf(stderr, "Usage: xfaget filename");
    exit(2);
  }
  fileName = new GooString(argv[1]);
  ownerPW = NULL;
  userPW = NULL;

  doc = PDFDocFactory().createPDFDoc(*fileName, ownerPW, userPW);

  if (!doc->isOk()) {
    fprintf(stderr, "Document is not OK");
    exit(3);
  }

  // print form info
  switch (doc->getCatalog()->getFormType())
  {
    case Catalog::NoForm:
      printf("Form:           none\n");
      break;
    case Catalog::AcroForm:
      printf("Form:           AcroForm\n");
      break;
    case Catalog::XfaForm:
      printf("Form:           XFA\n");
      break;
  }

  delete doc;
}
