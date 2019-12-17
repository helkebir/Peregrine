#include "PeregrineApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
PeregrineApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  return params;
}

PeregrineApp::PeregrineApp(InputParameters parameters) : MooseApp(parameters)
{
  PeregrineApp::registerAll(_factory, _action_factory, _syntax);
}

PeregrineApp::~PeregrineApp() {}

void
PeregrineApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"PeregrineApp"});
  Registry::registerActionsTo(af, {"PeregrineApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
PeregrineApp::registerApps()
{
  registerApp(PeregrineApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
PeregrineApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PeregrineApp::registerAll(f, af, s);
}
extern "C" void
PeregrineApp__registerApps()
{
  PeregrineApp::registerApps();
}
