package com.zq.zqplayer.fragment.topnavigation

import android.os.Bundle
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.View
import butterknife.BindView
import com.chad.library.adapter.base.entity.MultiItemEntity
import com.ziq.base.mvp.BaseFragment
import com.ziq.base.mvp.IBasePresenter
import com.zq.zqplayer.R
import com.zq.zqplayer.adapter.RecommendAdapter

/**
 * @author wuyanqiang
 * @date 2018/10/15
 */
class RecommendFragment : BaseFragment<IBasePresenter>() {

    @BindView(R.id.recycleView)
    lateinit var recycleView: RecyclerView;

    override fun initLayoutResourceId(): Int {
        return R.layout.fragment_recommend
    }

    override fun initData(view: View, savedInstanceState: Bundle?) {
        val data:ArrayList<MultiItemEntity> = arrayListOf();
        data.add(MultiItemEntity { RecommendAdapter.RECOMMEND_TYPE_SEARCH })
        data.add(MultiItemEntity { RecommendAdapter.RECOMMEND_TYPE_BANNER })
        val adapter = RecommendAdapter(data)
        recycleView.layoutManager = LinearLayoutManager(context)
        recycleView.adapter = adapter
    }

}