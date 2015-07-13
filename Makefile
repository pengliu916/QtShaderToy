#############################################################################
# Makefile for building: DX12Frame
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  DX12Frame.pro
# Template: app
# Command: D:\ProjectLibrary\qt5\qtbase\bin\qmake.exe -o Makefile DX12Frame.pro
#############################################################################

MAKEFILE      = Makefile

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = D:\ProjectLibrary\qt5\qtbase\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: DX12Frame.pro ..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\win32-msvc2015\qmake.conf ..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\spec_pre.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\common\msvc-desktop.conf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\qconfig.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dcore.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dcore_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dinput.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dinput_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquick.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquick_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquickrenderer.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquickrenderer_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3drenderer.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3drenderer_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axbase.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axserver.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_clucene_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_core.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_core_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_declarative.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_declarative_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_designer.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_gui.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_help.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_help_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_location.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_location_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_network.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_network_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_nfc.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_opengl.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_platformsupport_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_positioning.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qml.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quick.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_script.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_script_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_scripttools.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_scripttools_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sensors.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_serialport.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sql.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_svg.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_testlib.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_uiplugin.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_uitools.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_webchannel.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_webchannel_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_websockets.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_widgets.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_winextras.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xml.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_dumpcpp.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_dumpdoc.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_lconvert.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_lrelease.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_lupdate.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qcollectiongenerator.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qdoc.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qhelpgenerator.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qlalr.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qml.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qml1plugindump.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlimportscanner.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmljs.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmllint.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlmin.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlplugindump.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlprofiler.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlscene.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmltestrunner.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_syncqt.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_uic.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatterns.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatternsvalidator.pri \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\qt_functions.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\qt_config.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\qt_config.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\win32-msvc2015\qmake.conf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\spec_post.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\exclusive_builds.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\default_pre.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\default_pre.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\resolve_config.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\exclusive_builds_post.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\default_post.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\rtti.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\c++11.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\precompile_header.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\warn_on.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\qt.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\resources.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\moc.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\opengl.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\uic.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\windows.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\testcase_targets.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\exceptions.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\yacc.prf \
		..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\lex.prf \
		DX12Frame.pro \
		D:/ProjectLibrary/qt5/qtbase/lib/qtmain.prl \
		D:/ProjectLibrary/qt5/qtbase/lib/Qt5Widgets.prl \
		D:/ProjectLibrary/qt5/qtbase/lib/Qt5Gui.prl \
		D:/ProjectLibrary/qt5/qtbase/lib/Qt5Core.prl \
		D:/ProjectLibrary/qt5/qtbase/lib/libEGL.prl \
		D:/ProjectLibrary/qt5/qtbase/lib/libGLESv2.prl
	$(QMAKE) -o Makefile DX12Frame.pro
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\spec_pre.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\common\msvc-desktop.conf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\qconfig.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dcore.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dcore_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dinput.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dinput_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquick.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquick_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquickrenderer.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3dquickrenderer_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3drenderer.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_3drenderer_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axbase.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axserver.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_clucene_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_concurrent.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_core.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_core_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_declarative.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_declarative_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_designer.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_designer_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_gui.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_gui_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_help.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_help_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_location.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_location_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimedia.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_network.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_network_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_nfc.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_opengl.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_platformsupport_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_positioning.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_printsupport.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qml.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qml_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qmltest.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quick.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quick_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_script.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_script_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_scripttools.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_scripttools_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sensors.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_serialport.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sql.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_sql_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_svg.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_svg_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_testlib.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_uiplugin.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_uitools.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_webchannel.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_webchannel_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_websockets.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_widgets.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_winextras.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xml.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xml_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_dumpcpp.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_dumpdoc.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_lconvert.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_lrelease.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_lupdate.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qcollectiongenerator.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qdoc.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qhelpgenerator.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qlalr.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qml.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qml1plugindump.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlimportscanner.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmljs.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmllint.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlmin.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlplugindump.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlprofiler.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmlscene.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_qmltestrunner.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_syncqt.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_uic.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatterns.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\modules\qt_tool_xmlpatternsvalidator.pri:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\qt_functions.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\qt_config.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\qt_config.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\win32-msvc2015\qmake.conf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\spec_post.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\exclusive_builds.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\default_pre.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\default_pre.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\resolve_config.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\exclusive_builds_post.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\default_post.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\rtti.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\c++11.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\precompile_header.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\warn_on.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\qt.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\resources.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\moc.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\opengl.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\uic.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\win32\windows.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\testcase_targets.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\exceptions.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\yacc.prf:
..\..\..\ProjectLibrary\qt5\qtbase\mkspecs\features\lex.prf:
DX12Frame.pro:
D:/ProjectLibrary/qt5/qtbase/lib/qtmain.prl:
D:/ProjectLibrary/qt5/qtbase/lib/Qt5Widgets.prl:
D:/ProjectLibrary/qt5/qtbase/lib/Qt5Gui.prl:
D:/ProjectLibrary/qt5/qtbase/lib/Qt5Core.prl:
D:/ProjectLibrary/qt5/qtbase/lib/libEGL.prl:
D:/ProjectLibrary/qt5/qtbase/lib/libGLESv2.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile DX12Frame.pro

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
	-$(DEL_FILE) DX12Frame.exp
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) DX12Frame.lib

release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile