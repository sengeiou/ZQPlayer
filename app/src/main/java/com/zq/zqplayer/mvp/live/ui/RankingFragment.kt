package com.zq.zqplayer.mvp.live.ui

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import com.ziq.base.mvp.BaseFragment
import com.ziq.base.mvp.IBasePresenter
import com.ziq.base.mvp.dagger.component.AppComponent
import com.zq.zqplayer.R

/**
 * @author wuyanqiang
 * @date 2018/10/15
 */
class RankingFragment : BaseFragment<IBasePresenter>() {
    override fun initForInject(appComponent: AppComponent?) {
    }
    override fun initLayoutResourceId(): Int {
        return R.layout.fragment_ranking
    }

    override fun initData(view: View, savedInstanceState: Bundle?) {

    }

}