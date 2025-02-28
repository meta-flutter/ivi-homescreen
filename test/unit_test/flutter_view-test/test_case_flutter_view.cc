#include <stdexcept>
#include "gtest/gtest.h"
#include "utils.h"
#include "view/flutter_view.h"
#include "view/compositor_surface_api.h"
#include "wayland/display.h"
#include "unit_test_utils.h"

FlutterView* createFlutterViewInstance() {
  int argc = 3;
  const char* argv[3] = {"homescreen",
                         "-b",kBundlePath};
  char** argv_p = reinterpret_cast<char**>(&argv);

  // call target function
  const auto configs = Configuration::ParseArgcArgv(argc, argv_p);

  Configuration::Config config = configs.back();

  auto wayland_display = std::make_shared<Display>(false, "", "", configs);
  auto* view = new FlutterView(config, 0, wayland_display);
  return view;
}

/****************************************************************
Test Case Name.Test Name： HomescreenFlutterViewConstructor_Lv1Normal001
Use Case Name: Provide wayland client function
Test Summary：Test the constructor of FlutterView class
***************************************************************/
TEST(HomescreenFlutterViewConstructor, Lv1Normal001) {
  // call target function
  FlutterView* view = createFlutterViewInstance();

  // confirm to create instance
  EXPECT_TRUE(view != nullptr);
}

#if 0
/****************************************************************
Test Case Name.Test Name： HomescreenFlutterViewCreateSurface_Lv1Normal001
Use Case Name: Provide wayland client function
Test Summary：Test the function of CreateSurface
***************************************************************/
TEST(HomescreenFlutterViewCreateSurface, Lv1Normalcase001) {
  FlutterView* view = createFlutterViewInstance();

  // call target function
  int h_module = 0;
  size_t surf_index = view->CreateSurface(
      &h_module, "", "", "", CompositorSurface::PARAM_SURFACE_T::egl,
      CompositorSurface::PARAM_Z_ORDER_T::above,
      CompositorSurface::PARAM_SYNC_T::sync, kDefaultViewWidth,
      kDefaultViewHeight, 0, 0);

  // check comp_surf array index and the array is not empty
  EXPECT_EQ(0, surf_index);
  EXPECT_FALSE(view->m_comp_surf.empty());
}

/****************************************************************
Test Case Name.Test Name： HomescreenFlutterViewDisposeSurface_Lv1Normal001
Use Case Name: Provide wayland client function
Test Summary：Test the function of DisposeSurface
***************************************************************/
TEST(HomescreenFlutterViewDisposeSurface, Lv1Normalcase001) {
  FlutterView* view = createFlutterViewInstance();

  int h_module = 0;
  view->CreateSurface(&h_module, "", "", "",
                      CompositorSurface::PARAM_SURFACE_T::egl,
                      CompositorSurface::PARAM_Z_ORDER_T::above,
                      CompositorSurface::PARAM_SYNC_T::sync, kDefaultViewWidth,
                      kDefaultViewHeight, 0, 0);

  // check comp_surf array is not empty
  EXPECT_FALSE(view->m_comp_surf.empty());

  // call target function
  view->DisposeSurface(0);

  // check comp_surf array content was deleted
  EXPECT_TRUE(view->m_comp_surf.empty());
}

/****************************************************************
Test Case Name.Test Name： HomescreenFlutterViewGetSurfaceContext_Lv1Normal002
Use Case Name: Provide wayland client function
Test Summary：Test the function of DrawFps
***************************************************************/
TEST(HomescreenFlutterViewDrawFps, Lv1Normalcase001) {
    FlutterView* view = createFlutterViewInstance();

    int h_module = 0;
    view->CreateSurface(
        &h_module, "", "", "",
        CompositorSurface::PARAM_SURFACE_T::egl,
        CompositorSurface::PARAM_Z_ORDER_T::above,
        CompositorSurface::PARAM_SYNC_T::sync,
        kDefaultViewWidth,
        kDefaultViewHeight,
        0,
        0
    );

    // call target function with invalid index
    view->DrawFps(1);
}

/****************************************************************
Test Case Name.Test Name： HomescreenFlutterViewGetSurfaceContext_Lv1Normal001
Use Case Name: Provide wayland client function
Test Summary：Test the function of GetSurfaceContext
***************************************************************/
TEST(HomescreenFlutterViewGetSurfaceContext, Lv1Normalcase001) {
    FlutterView* view = createFlutterViewInstance();

    int h_module = 0;
    view->CreateSurface(
        &h_module, "", "", "",
        CompositorSurface::PARAM_SURFACE_T::egl,
        CompositorSurface::PARAM_Z_ORDER_T::above,
        CompositorSurface::PARAM_SYNC_T::sync,
        kDefaultViewWidth,
        kDefaultViewHeight,
        0,
        0
    );

    // call target function
    auto *ret_context = view->GetSurfaceContext(0);

    // Deleted mock functions that set value m_context at InitializePlugin.
    // So m_context is null pointer.
    EXPECT_TRUE(ret_context == nullptr);
}

/****************************************************************
Test Case Name.Test Name： HomescreenFlutterViewGetSurfaceContext_Lv1Normal002
Use Case Name: Provide wayland client function
Test Summary：Test the function of GetSurfaceContext
***************************************************************/
TEST(HomescreenFlutterViewGetSurfaceContext, Lv1Normalcase002) {
    FlutterView* view = createFlutterViewInstance();

    int h_module = 0;
    view->CreateSurface(
        &h_module, "", "", "",
        CompositorSurface::PARAM_SURFACE_T::egl,
        CompositorSurface::PARAM_Z_ORDER_T::above,
        CompositorSurface::PARAM_SYNC_T::sync,
        kDefaultViewWidth,
        kDefaultViewHeight,
        0,
        0
    );

    // call target function with invalid index
    auto *ret_context = view->GetSurfaceContext(2);

    EXPECT_TRUE(ret_context == nullptr);
}
#endif
