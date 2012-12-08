#ifndef CSM_DOC_DOCUMENT_H
#define CSM_DOC_DOCUMENT_H

#include <string>

#include <QUndoStack>
#include <QObject>
#include <QTimer>

#include "../world/data.hpp"

#include "../tools/tools.hpp"

#include "state.hpp"

namespace CSMDoc
{
    class Document : public QObject
    {
            Q_OBJECT

        private:

            std::string mName; ///< \todo replace name with ESX list
            QUndoStack mUndoStack;
            CSMWorld::Data mData;
            CSMTools::Tools mTools;

            int mSaveCount; ///< dummy implementation -> remove when proper save is implemented.
            QTimer mSaveTimer; ///< dummy implementation -> remove when proper save is implemented.

            int mVerifyCount; ///< dummy implementation -> remove when proper verify is implemented.

            // not implemented
            Document (const Document&);
            Document& operator= (const Document&);

        public:

            Document (const std::string& name);
            ///< \todo replace name with ESX list

            QUndoStack& getUndoStack();

            int getState() const;

            const std::string& getName() const;
            ///< \todo replace with ESX list

            void save();

            void verify();

            void abortOperation (int type);

            const CSMWorld::Data& getData() const;

            CSMWorld::Data& getData();

        signals:

            void stateChanged (int state, CSMDoc::Document *document);

            void progress (int current, int max, int type, int threads, CSMDoc::Document *document);

        private slots:

            void modificationStateChanged (bool clean);

            void operationDone (int type);

            void saving();
            ///< dummy implementation -> remove when proper save is implemented.

        public slots:

            void progress (int current, int max, int type);
    };
}

#endif